#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
 
#define rows_size 7
#define columns_size 8


struct route
{
    int x;
    int y;
    double d;
};

struct box
{
    int col, row;
    int * n;
    int n_len;
    double f, g, h;
    int from;
};

 
char map[rows_size][columns_size] =
{
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

int draw_way[rows_size][columns_size] =
{
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1}
};
 
int main()
{
    int i, j, k, l, m, ok;
    int pick_len = 0;
    int * way = NULL;
    int closed_len = 0;
    int * closed = NULL;
    int ready_len = 1;
    int * ready = (int*)calloc(ready_len, sizeof(int));
    double min, aux;
    int start;
    int end;
    int current;
    int start_len = 0;
    struct box * stops = NULL;
    int root_len = 0;
    struct route * routes = NULL;
 

    for (i = 1; i < rows_size - 1; i ++)
    {
        for (j = 1; j < columns_size - 1; j ++)
        {
            if (!map[i][j])
            {
                ++start_len;
                stops = (struct box *)realloc(stops, start_len * sizeof(struct box));
                int t = start_len - 1;
                stops[t].col = j;
                stops[t].row = i;
                stops[t].from = -1;
                stops[t].g = DBL_MAX;
                stops[t].n_len = 0;
                stops[t].n = NULL;
                draw_way[i][j] = t;
            }
        }
    }
 
    start = 0;
    end = start_len - 1;
 
    for (i = 0; i < start_len ; i++)
    {
        stops[i].h = sqrt(pow(stops[end].row - stops[i].row, 2) + pow(stops[end].col - stops[i].col, 2));
    }
 
    for (i = 1; i < rows_size - 1; i ++)
    {
        for (j = 1; j < columns_size - 1; j ++)
        {
            if (draw_way[i][j] >= 0)
            {
                for (k = i - 1; k <= i + 1; k ++)
                {
                    for (l = j - 1; l <= j + 1; l ++)
                    {
                        if (k == i && l == j) 
                            continue;
 
                        if (draw_way[k][l] >= 0)
                        {
                            ++root_len;
                            routes = (struct route *)realloc(routes, root_len * sizeof(struct route));
                            int t = root_len - 1;
                            routes[t].x = draw_way[i][j];
                            routes[t].y = draw_way[k][l];
                            routes[t].d = sqrt(pow(stops[routes[t].y].row - stops[routes[t].x].row, 2) + pow(stops[routes[t].y].col - stops[routes[t].x].col, 2));
                            ++stops[routes[t].x].n_len;
                            stops[routes[t].x].n = (int*)realloc(stops[routes[t].x].n, stops[routes[t].x].n_len * sizeof(int));
                            stops[routes[t].x].n[stops[routes[t].x].n_len - 1] = t;
                        }
                    }
                }
            }
        }
    }
 
    ready[0] = start;
    stops[start].g = 0;
    stops[start].f = stops[start].g + stops[start].h;
    ok = 0;
 
    while (ready_len && !ok)
    {
        min = DBL_MAX;
 
        for (i = 0; i < ready_len; i ++)
        {
            if (stops[ready[i]].f < min)
            {
                current = ready[i];
                min = stops[ready[i]].f;
            }
        }
 
        if (current == end)
        {
            ok = 1;
            ++pick_len;
            way = (int*)realloc(way, pick_len * sizeof(int));
            way[pick_len - 1] = current;
            while (stops[current].from >= 0)
            {
                current = stops[current].from;
                ++pick_len;
                way = (int*)realloc(way, pick_len * sizeof(int));
                way[pick_len - 1] = current;
            }
        }
 
        for (i = 0; i < ready_len; i ++)
        {
            if (ready[i] == current)
            {
                if (i != (ready_len - 1))
                {
                    for (j = i; j < (ready_len - 1); j ++)
                    {
                        ready[j] = ready[j + 1];
                    }
                }
                --ready_len;
                ready = (int*)realloc(ready, ready_len * sizeof(int));
                break;
            }
        }
 
        ++closed_len;
        closed = (int*)realloc(closed, closed_len * sizeof(int));
        closed[closed_len - 1] = current;
 
        for (i = 0; i < stops[current].n_len; i ++)
        {
            m = 0;
            for (j = 0; j < closed_len; j ++)
            {
                if (routes[stops[current].n[i]].y == closed[j])
                {
                    m = 1;
                }
            }
 
            if (m) 
            {
                continue;
            }
 
            aux = stops[current].g + routes[stops[current].n[i]].d;
            m = 1;
 
            if (ready_len > 0)
            {
                for (j = 0; j < ready_len; j ++)
                {
                    if (routes[stops[current].n[i]].y == ready[j]) 
                    {
                        m = 0;
                    }
                }
            }
 
            if (m || (aux < stops[routes[stops[current].n[i]].y].g))
            {
                stops[routes[stops[current].n[i]].y].from = current;
                stops[routes[stops[current].n[i]].y].g = aux;
                stops[routes[stops[current].n[i]].y].f = stops[routes[stops[current].n[i]].y].g + stops[routes[stops[current].n[i]].y].h;
 
                if (m)
                {
                    ++ready_len;
                    ready = (int*)realloc(ready, ready_len * sizeof(int));
                    ready[ready_len - 1] = routes[stops[current].n[i]].y;
                }
            }
        }
    }
 
    for (i = 0; i < rows_size; i ++)
    {
        for (j = 0; j < columns_size; j ++)
        {
            if (map[i][j]) 
            {
                putchar('|');
            }
            else
            {
                m = 0;
                for (k = 0; k <= pick_len; k ++)
                {
                    if (draw_way[i][j] == way[k])
                    {
                        ++m;
                    }
                }
                if (m)
                {
                    putchar('x');
                }
                else
                {
                    putchar('.');
                }
            }
        }
        putchar('\n');
    }
 
    if (!ok)
    {
        puts("NU ESTE POSIBIL! \n");
    }
    else
    {
        printf("\nTraseul este: %d:\n\n", pick_len);
        for (i = pick_len - 1; i >= 0; i --)
        {
            printf("(%d, %d)\n", stops[way[i]].col, stops[way[i]].row);
        }
    }
 
    for (i = 0; i < start_len; ++ i) 
    {
        free(stops[i].n);
    }
 
    free(stops);
    free(routes);
    free(way);
    free(ready);
    free(closed);
 

    return 0;
}