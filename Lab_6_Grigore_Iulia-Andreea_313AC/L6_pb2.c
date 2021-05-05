#include<stdio.h>
#include<stdlib.h>
#define MAX 5

//Reprezentarea grafica a grafului:
//         
//              0
//            / | \
//           1  2  3
//           |
//           4
//
//Matricea de adiacenta a grafului(orientat):
int matrix[MAX][MAX] = {{0,1,1,1,0},
                        {0,0,0,0,1},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}};

int vertex_values[MAX] = {0,1,2,3,4};

void verifica_existenta_drumului_intre_noduri(int first, int second, int x)
{
    int i, j, nr = 0;

    if(x == 1)
    {
        for(i = 0; i < MAX; i++)
        {   if(vertex_values[i] == first)
            {   for(j = 0; j < MAX; j++)
                {   
                    if(matrix[i][j] == 1 && vertex_values[j] == second)
                    {   
                        printf("\nExista drum intre nodurile %d si %d.\n", first, second);
                        exit(1);
                    }
                    if(matrix[i][j] == 1)
                    {
                        nr++;
                    }
                }
            }
        }
        if(nr != 0)
        {
            x = 0;
        }
    }
      
    if(x == 0)
    {
        for(i = 0; i < MAX; i++)
        {   if(vertex_values[i] == first)
            {   for(j = 0; j < MAX; j++)
                {   
                    if(matrix[i][j] == 1 && vertex_values[j] == second)
                    {   
                        printf("\nExista drum intre nodurile %d si %d.\n", first, second);
                        exit(1); 
                    }
                    else if(matrix[i][j] == 1 && vertex_values[j] != second && j <= second)
                    {
                        verifica_existenta_drumului_intre_noduri(j, second, 0);
                    }    
                }
            }
        }
    } 
    
    printf("\nNu exista drum intre nodurile %d si %d.\n", first, second);
}
int main()
{
    int node1, node2;


    printf("Verificati daca exista drum intre urmatoarele noduri(cu valori de la 0, la 4), first < second;\n");
    printf("Introduceti valoarea primului nod: ");
    scanf("%d", &node1);

    printf("Introduceti valoarea celui de-al doilea nod: ");
    scanf("%d", &node2);

    if(node1 >= node2)
    {
        while(node1 >= node2)
        {
            printf("\nPrimul nod este strict mai mic decat al doilea nod!\n");
            printf("Introduceti alte date:\n");

            printf("Introduceti valoarea primului nod: ");
            scanf("%d", &node1);

            printf("Introduceti valoarea celui de-al doilea nod: ");
            scanf("%d", &node2);
        }
        
    }

    verifica_existenta_drumului_intre_noduri(node1, node2, 1);

    
    return 0;
}