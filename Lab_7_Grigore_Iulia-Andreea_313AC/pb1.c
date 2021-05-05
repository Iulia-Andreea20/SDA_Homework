#include<stdio.h>

//Reprezentarea grafica a grafului(este acelasi pentru graph1 si graph2):
//
//             1     3
//          1 --- 2 --- 6
//          |     |     |
//        5 |   1 |     | 1
//          |     |  5  |  
//          3 --- 4 --- 5 --- 8
//             2        |  1  |
//                    3 |     | 4
//                      |     |
//                      7     9
//                            |
//                            | 2
//                            |
//                           10

typedef struct component
{
    int node1, node2;
    int cost;
}COMPONENT;

void create_graph(COMPONENT graph1[11], COMPONENT graph2[11])
{

    graph1[0].node1 = 1;
    graph1[0].node2 = 2;
    graph1[0].cost = 1;
    graph2[0].node1 = 1;
    graph2[0].node2 = 2;
    graph2[0].cost = 1;

    graph1[1].node1 = 1;
    graph1[1].node2 = 3;
    graph1[1].cost = 5;
    graph2[1].node1 = 1;
    graph2[1].node2 = 3;
    graph2[1].cost = 5;

    graph1[2].node1 = 2;
    graph1[2].node2 = 4;
    graph1[2].cost = 1;
    graph2[2].node1 = 2;
    graph2[2].node2 = 4;
    graph2[2].cost = 1;

    graph1[3].node1 = 6;
    graph1[3].node2 = 2;
    graph1[3].cost = 3;
    graph2[3].node1 = 2;
    graph2[3].node2 = 6;
    graph2[3].cost = 3;

    graph1[4].node1 = 3;
    graph1[4].node2 = 4;
    graph1[4].cost = 2;
    graph2[4].node1 = 3;
    graph2[4].node2 = 4;
    graph2[4].cost = 2;

    graph1[5].node1 = 4;
    graph1[5].node2 = 5;
    graph1[5].cost = 5;
    graph2[5].node1 = 4;
    graph2[5].node2 = 5;
    graph2[5].cost = 5;

    graph1[6].node1 = 6;
    graph1[6].node2 = 5;
    graph1[6].cost = 1;
    graph2[6].node1 = 5;
    graph2[6].node2 = 6;
    graph2[6].cost = 1;

    graph1[7].node1 = 5;
    graph1[7].node2 = 7;
    graph1[7].cost = 3;
    graph2[7].node1 = 5;
    graph2[7].node2 = 7;
    graph2[7].cost = 3;

    graph1[8].node1 = 5;
    graph1[8].node2 = 8;
    graph1[8].cost = 1;
    graph2[8].node1 = 5;
    graph2[8].node2 = 8;
    graph2[8].cost = 1;

    graph1[9].node1 = 8;
    graph1[9].node2 = 9;
    graph1[9].cost = 4;
    graph2[9].node1 = 8;
    graph2[9].node2 = 9;
    graph2[9].cost = 4;

    graph1[10].node1 = 9;
    graph1[10].node2 = 10;
    graph1[10].cost = 2;
    graph2[10].node1 = 9;
    graph2[10].node2 = 10;
    graph2[10].cost = 2;

}

void display_data(COMPONENT minimum_spanning_tree[20], int tree_position, int algorithm)
{
    int i, j, total_cost = 0;
    int unique_nodes[10], nr_nodes = 0;
    int ok1, ok2;


    for(i = 0; i <= tree_position; i++)
    {
        if(i == 0)
        {
            unique_nodes[0] = minimum_spanning_tree[i].node1;
            unique_nodes[1] = minimum_spanning_tree[i].node2;
            nr_nodes = 1;
        }
        else
        {
            ok1 = 1;
            ok2 = 1;

            for(j = 0; j <= nr_nodes; j++)
            {   
                if(minimum_spanning_tree[i].node1 == unique_nodes[j] && ok1 == 1)
                {
                    ok1 = 0;
                }

                if(minimum_spanning_tree[i].node2 == unique_nodes[j] && ok2 == 1)
                {
                    ok2 = 0;
                }  
            }
            if(ok1 == 1)
            {
                nr_nodes++;
                unique_nodes[nr_nodes] = minimum_spanning_tree[i].node1;
            }

            if(ok2 == 1)
            {
                nr_nodes++;
                unique_nodes[nr_nodes] = minimum_spanning_tree[i].node2;
            }
        }
    }
    if(algorithm == 1)
    {
        printf("\nCu alghoritmul Kruskal:\n");
        printf("Nodurile sunt: ");
        for(i = 0; i <= nr_nodes; i++)
        {
            printf("%d ", unique_nodes[i]);
        }
        printf("\n");

        printf("Valorile muchiilor din arbore sunt: ");
        for(i = 0; i <= tree_position; i++)
        {
            printf("%d ", minimum_spanning_tree[i].cost);
            total_cost += minimum_spanning_tree[i].cost;
        }

        printf("\nPretul total este: %d\n", total_cost);
    }
    else
    {
        printf("\nCu alghoritmul Prim:\n");
        printf("Nodurile sunt: ");
        for(i = 0; i <= nr_nodes; i++)
        {
            printf("%d ", unique_nodes[i]);
        }
        printf("\n");

        printf("Valorile muchiilor din arbore sunt: ");
        for(i = 0; i <= tree_position; i++)
        {
            printf("%d ", minimum_spanning_tree[i].cost);
            total_cost += minimum_spanning_tree[i].cost;
        }

        printf("\nPretul total este: %d\n\n", total_cost);
    }

}

void Kruskal(COMPONENT graph[20], COMPONENT minimum_spanning_tree[20])
{
    int i, j, k;
    COMPONENT aux;
    int tree_position = -1;
    int ok_tree;

    
    for(i = 0; i < 11; i++)
    {
        for(j = i + 1; j < 11; j++)
        {
            if(graph[i].cost > graph[j].cost)
            {
                aux.node1 = graph[i].node1;
                aux.node2 = graph[i].node2;
                aux.cost = graph[i].cost;

                graph[i].node1 = graph[j].node1;
                graph[i].node2 = graph[j].node2;
                graph[i].cost = graph[j].cost;

                graph[j].node1 = aux.node1;
                graph[j].node2 = aux.node2;
                graph[j].cost = aux.cost;

            }
        }
    }

    for(i = 0; i < 11; i++)
    {
        if(i == 0)
        {
            tree_position++;
            minimum_spanning_tree[tree_position].node1 = graph[i].node1;
            minimum_spanning_tree[tree_position].node2 = graph[i].node2;
            minimum_spanning_tree[tree_position].cost= graph[i].cost;
        }
        else
        {
            ok_tree = 1;
            for(j = 0; j <= tree_position; j++)
            {
                if(graph[i].node1 == minimum_spanning_tree[j].node1)
                {
                    for(k = j + 1; k <= tree_position; k++)
                    {
                        if(graph[i].node2 == minimum_spanning_tree[k].node1)
                        {
                            ok_tree = 0;
                            break;

                        }
                    }
                }
                else if(graph[i].node1 == minimum_spanning_tree[j].node2)
                {
                    for(k = j + 1; k <= tree_position; k++)
                    {
                        if(graph[i].node2 == minimum_spanning_tree[k].node2)
                        {
                            ok_tree = 0;
                            break;

                        }
                    }
                }
            }
            if(ok_tree == 1)
            {
                tree_position++;
                minimum_spanning_tree[tree_position].node1 = graph[i].node1;
                minimum_spanning_tree[tree_position].node2 = graph[i].node2;
                minimum_spanning_tree[tree_position].cost= graph[i].cost;
            }
        }
    }

    display_data(minimum_spanning_tree, tree_position, 1);
}

void Prim(COMPONENT graph[11], COMPONENT minimum_spanning_tree[11])
{
    COMPONENT aux_edges[10], aux, edges[11];
    int i, j, k = 0, minimum_point, position = 0, minimum;
    int node = 1, aux1, aux2;
    int visited_nodes[10], unique[10];
    int dimension = -1;


    for(i = 0; i < 11; i++)
    {
        for(j = i + 1; j < 11; j++)
        {
            if(graph[i].node1 > graph[j].node1)
            {
                aux.node1 = graph[i].node1;
                aux.node2 = graph[i].node2;
                aux.cost = graph[i].cost;

                graph[i].node1 = graph[j].node1;
                graph[i].node2 = graph[j].node2;
                graph[i].cost = graph[j].cost;

                graph[j].node1 = aux.node1;
                graph[j].node2 = aux.node2;
                graph[j].cost = aux.cost;
            }
        }
    }

    while(node <= 9)
    {
        minimum = 10;
        visited_nodes[k] = node;
        k++;
        for(i = 0; i < 11; i++)
        {
            if(graph[i].node1 == node)
            {
                edges[position].node1 = graph[i].node1;
                edges[position].node2 = graph[i].node2;
                edges[position].cost = graph[i].cost;
                position++; 

            }
            else if(graph[i].node1 > node)
            {
                break;
            }
        }

        for(j = 0; j < position; j++)
        {
            if(edges[j].cost < minimum)
            {
                minimum_point = j;
                minimum = edges[j].cost;
                aux1 = edges[j].node1;
                aux2 = edges[j].node2;
            }
        }
        for(j = minimum_point; j < position; j++)
        {
            edges[j].node1 = edges[j + 1].node1;
            edges[j].node2 = edges[j + 1].node2;
            edges[j].cost = edges[j + 1].cost;
        }
        position--;

        dimension++;

        minimum_spanning_tree[dimension].node1 = aux1;
        minimum_spanning_tree[dimension].node2 = aux2;
        minimum_spanning_tree[dimension].cost = minimum;

        node++;
    }

    display_data(minimum_spanning_tree, dimension, 2);

}

int main()
{
    COMPONENT graph1[11], graph2[11], minimum_spanning_tree_kruskal[11];
    COMPONENT minimum_spanning_tree_prim[11];
    int tree_position = -1, i;


    create_graph(graph1, graph2);
    Kruskal(graph1, minimum_spanning_tree_kruskal);
    Prim(graph2, minimum_spanning_tree_prim);


    return 0;
}