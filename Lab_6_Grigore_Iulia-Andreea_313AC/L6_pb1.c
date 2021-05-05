#include<stdio.h>
#include<stdlib.h>
#define MAX 6

//Reprezentarea grafica a grafului:
//         
//              0
//            / | \
//           1  2  3
//           |  |
//           4  5
//
//Matricea de adiacenta a grafului(neorientat):
int matrix[MAX][MAX] = {{0,1,1,1,0,0},
                        {1,0,0,0,1,0},
                        {1,0,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,0,0},
                        {0,0,1,0,0,0}};

int vertex_values[MAX] = {0,1,2,3,4,5};
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

int queue_isEmpty()
{
    if(rear == -1 && front == -1)
        return 1;
    return 0;
}
void initialize_queue()
{
    front = 0;
    rear = 0;
    queue[rear] = vertex_values[rear];
}
void Enqueue()
{  
    rear++;
    queue[rear] = vertex_values[rear]; 
}
void Dequeue()
{
    if(queue_isEmpty() == 0)
    {
        if(front == rear)
        {
            queue[front] = 0;
            front = -1;
            rear = -1;
        }
        else
        {
            queue[front] = 0; 
            front++; 
        }
        
    }

}
void BFS()
{
    int i = 0, j = 0, nr = 0;


    initialize_queue();
    printf("%d ", queue[rear]);

    while(queue_isEmpty() == 0 && i < MAX)
    {
        for(j = 0; j < MAX; j++)
        {
            if(matrix[i][j] == 1)
            {
                matrix[j][i] = 0;
                Enqueue();
                printf("%d ", queue[rear]);    
            }
        }
        Dequeue();
        i++;
    }
    printf("\n");   
}

int stack_isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}
void push(int column)
{
    top++;
    stack[top] = vertex_values[column]; 
}
void pop()
{
    if(stack_isEmpty() == 0)
    {
        stack[top] = 0;
        top--;
    }    
}

int number_nodes(int line)
{
    int nr = 0, i = 0;

    for(i = 0;i < MAX; i++)
    {
       if(matrix[line][i] == 1)
       {
           nr++;
       }
    }

    return nr;
}
void DFS()
{
    int i = 0, j;

    printf("%d ", vertex_values[0]);
    if(number_nodes(i) > 1)
    {
        
        for(j = MAX - 1; j >= 0; j--)
        {
            if(matrix[i][j] == 1)
            {
                matrix[j][i] = 0;
                push(j);
            }
        }
    }
    i++;
    while(stack_isEmpty() == 0 && i < MAX)
    {
        if(number_nodes(i) > 1)
        {
            
            for(j = MAX - 1; j >= 0; j--)
            {
                if(matrix[i][j] == 1)
                {
                    matrix[j][i] = 0;
                    push(j);
                }
            }
        }
        else if(number_nodes(i) == 1)
        {
            for(j = MAX - 1; j >= 0; j--)
            {
                if(matrix[i][j] == 1)
                {
                    printf("%d %d ", stack[top], vertex_values[j]);
                    pop();
                    break;
                }
            }
        }
        else
        {
            printf("%d ", stack[top]);
            pop();
        }
            
        i++;
    }   
    printf("\n");
}
int main()
{
    printf("Parcurgerea BFS a grafului: ");
    BFS();

    printf("Parcurgerea DFS a grafului: ");   
    DFS();
    

    return 0;
}