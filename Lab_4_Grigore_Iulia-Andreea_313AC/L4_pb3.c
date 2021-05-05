#include<stdio.h>
#define MAX 10

int s1[MAX], s2[MAX], queue[MAX];
int top1 = -1, top2 = -1, front = -1, rear = -1;
int s1_isEmpty()
{
    if(top1 == -1)
        return 1;
    return 0;
}

int s2_isEmpty()
{
    if(top2 == -1)
        return 1;
    return 0;
}

int s1_isFull()
{
    if(top1 == MAX - 1)
        return 1;
    return 0;
}

int s2_isFull()
{
    if(top2 == MAX - 1)
        return 1;
    return 0;
}

void push(int value)
{
    top1++;
    s1[top1] = value;
}

void enqueue()
{
    int value;

    if(s1_isFull() == 1)
    {
        printf("\nCoada este plina!\n");
    }
    else
    {
        printf("Introduceti valoarea pe care vreti s-o adaugati in stiva: ");
        scanf("%d", &value);
        push(value);
    }
}
void pop()
{
    s2[top2] = 0;
    top2--;
}
void dequeue()
{
    int i;

    if(s2_isEmpty() == 1 && s1_isEmpty() == 1)
    {
        printf("\nCoada este goala!\n");
    }
    else if(s1_isEmpty() == 0 && s2_isEmpty() == 1)
    {
        for(i = top1; i >= 0; i--)
            {
                top2++;
                s2[top2] = s1[i];
            }
        top1 = -1;
        pop();
        
    }
    else if(s2_isEmpty() == 0)
    {
        pop();
        
    }
}

void create_queue()
{
    int i;
    front = 0;
    rear = -1;
    if(s1_isEmpty() == 1)
    {   
        for(i = top2; i >= 0; i--)
            {
                rear++;
                queue[rear] = s2[i];
            }
    }
    else if(s2_isEmpty() == 1)
    {
        for(i = 0; i <= top1; i++)
        {
            rear++;
            queue[rear] = s1[i];
        }
    }
    else if(s2_isEmpty() == 0 && s1_isEmpty() == 0)
    {
        for(i = top2; i >= 0; i--)
        {
            rear++;
            queue[rear] = s2[i];
        }
        for(i = 0; i <= top1; i++)
        {
            rear++;
            queue[rear] = s1[i];
        }
    }

}
void display_queue()
{
    int i;

    create_queue();
    if(s1_isEmpty() == 1 && s2_isEmpty() == 1)
    {
        printf("\nCoada este goala!\n");
    }
    else
    {
        printf("\nCoada este: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
    
}
int main()
{
    char x = 'Y';

    printf("\nPuteti realiza urmatoarele actiuni:\n\n");
    printf("E: Adaugati un element in coada;\n");
    printf("D: Stergeti un element din coada\n");
    printf("S: Afisati coada;\n");
    printf("X: Iesiti din program.\n\n");

    while(x != 'X')
    {
        printf("Introduceti o actiune: ");
        scanf(" %c", &x);
        switch (x)
        {
        case 'E':
            enqueue();
            break;
        case 'D':
            dequeue();
            break;
        case 'S':
            display_queue();
            break;
        case 'X':
            break;
        default:
            printf("\nActiune necunoscuta!\n");
            break;
        }
    }

    return 0;
}