#include <stdio.h>
#define INFINITY 9999
#define INT_MAX 10

// int graph[INT_MAX][INT_MAX] =   {{0, 5, 0, -2, 3, -9, 0, 4, 0, 0},
//                                  {-5, 0, 3, 0, 4, 0, -2, 0, 0, 0},
//                                  {0, -2, 0, 0, 0, 8, 0, 0, 0, 0},
//                                  {-1, 0, 0, 0, 5, 0, 0, 0, -5, -7},
//                                  {-6, -3, 0, -5, 0, 0, 0, -7, 0, -5},
//                                  {-5, 0, 6, 0, 0, 0, -8, 0, 1, 0},
//                                  {0, 2, 0, 0, 0, 5, 0, -4, -3, 0},
//                                  {-3, 0, 0, 0, 8, 0, 5, 0, 2, 0},
//                                  {0, 0, 0, 5, 0, 7, -3, 1, 0, 7},
//                                  {0, 0, 0, 6, -5, 0, 0, 0, 7, 0}};


int graph[INT_MAX][INT_MAX] =   {{0, 5, 0, 2, 3, 9, 0, 4, 0, 0},
                                 {5, 0, 3, 0, 4, 0, 2, 0, 0, 0},
                                 {0, 2, 0, 0, 0, 8, 0, 0, 0, 0},
                                 {1, 0, 0, 0, 5, 0, 0, 0, 5, 7},
                                 {6, 3, 0, 5, 0, 0, 0, 7, 0, 5},
                                 {5, 0, 6, 0, 0, 0, 8, 0, 1, 0},
                                 {0, 2, 0, 0, 0, 5, 0, 4, 3, 0},
                                 {3, 0, 0, 0, 8, 0, 5, 0, 2, 0},
                                 {0, 0, 0, 5, 0, 7, 3, 1, 0, 7},
                                 {0, 0, 0, 6, 5, 0, 0, 0, 7, 0}};


void Dijkstra(int graph[INT_MAX][INT_MAX], int n, int beginning)
{
    int cost[INT_MAX][INT_MAX], distance[INT_MAX], pred[INT_MAX];
    int visited_nodes[INT_MAX], count, min_distance, next_node, i, j, x;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];
        }
            
    }
        


    for (i = 0; i < n; i++)
    {
        distance[i] = cost[beginning][i];
        pred[i] = beginning;
        visited_nodes[i] = 0;
    }

    distance[beginning] = 0;
    visited_nodes[beginning] = 1;
    count = 1;

    while (count < n - 1)
    {
        min_distance = INFINITY;

        for (i = 0; i < n; i++)
        {
            if (distance[i] < min_distance && !visited_nodes[i])
            {
                min_distance = distance[i];
                next_node = i;
            }
        }
            

        visited_nodes[next_node] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited_nodes[i])
            {
                if (min_distance + cost[next_node][i] < distance[i])
                {
                    distance[i] = min_distance + cost[next_node][i];
                    pred[i] = next_node;
                }
            }
        }
            
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != beginning)
        {
            printf("Distanta dintre nodul %d si nodul %d este: %d ", beginning + 1, i + 1, distance[i]);

            printf("\nDrumul dintre noduri este: %d", i + 1);
            j = i;
            do
            {
                j = pred[j];
                printf(" >> %d", j + 1);
            }
            while (j != beginning);
            printf("\n");

            printf("Valorile muchiilor sunt: ");
            j = i;
            do
            {
                printf("%d  ", graph[j][pred[j]]);
                j = pred[j];
            }
            while (j != beginning);
            printf("\n");
        }
}

void Bellman_Ford(int graph[INT_MAX][INT_MAX], int n, int beginning)
{
    int distance[INT_MAX], pred[INT_MAX], edge[INT_MAX * INT_MAX][2];
    int i, j, x, u, v, E;

    E = 0;
    for (i = 0; i < n; i ++)
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edge[E][0] = i;
                edge[E][1] = j;
                E++;
            }
        }

    for (i = 0; i < n; i++)
    {
        distance[i] = INFINITY;
        pred[i] = -1;
    }
    distance[beginning - 1] = 0;

    for (i = 0; i < n-1; i++)
    {
        for (x = 0; x < E; x++)
        {
            u = edge[x][0];
            v = edge[x][1];
            if (distance[u] != INFINITY && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }

    for (x=0; x<E; x++)
    {
        u = edge[x][0];
        v = edge[x][1];
        if (distance[u] != INFINITY && distance[u] + graph[u][v] < distance[v])
        {
            printf("Graful contine un ciclu negativ!!\n");
            return;
        }
    }

    for (i = 0; i < n; i++)
        if (i != beginning - 1)
        {
            printf("Distanta dintre nodul %d si nodul %d este: %d ", beginning, i + 1, distance[i]);

            printf("\nDrumul dintre noduri este: %d", i + 1);
            j = i;
            do{
                j = pred[j];
                printf(" >> %d", j + 1);
            }while (j != beginning - 1);
            printf("\n");


            printf("Valorile muchiilor sunt: ");
            j = i;
            do{
                printf("%d  ", graph[j][pred[j]]);
                j = pred[j];
            }while (j != beginning - 1);

            printf("\n");
        }
}

int main()
{
    int nodes, edges;
    nodes = 10;
    edges = 0;


    printf("\nDijkstra:\n\n");
    Dijkstra(graph, nodes, edges);

    edges = 1;
    printf("\n\nBellman-Ford:\n\n");
    Bellman_Ford(graph, nodes, edges);


    return 0;
}
