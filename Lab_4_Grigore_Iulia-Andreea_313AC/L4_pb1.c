#include<stdio.h>
#define MAX 10

int queue[MAX], stack[MAX];
int front = -1, rear = -1, top = -1;

int Queue_isEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

int Queue_isFull()
{
    if (rear == MAX - 1)
        return 1;
    return 0; 
}
void Enqueue()
{
    int value;

    if(Queue_isFull() == 1)
    {
        printf("Coada este plina!\n");
    }
    else if (Queue_isEmpty() == 1)
    {
        printf("Introduceti valoarea pe care vreti s-o adaugati in coada: ");
        scanf("%d", &value);
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        printf("Introduceti valoarea pe care vreti s-o adaugati in coada: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
        
    }
}
void Dequeue()
{
    if(Queue_isEmpty() == 1)
    {
        printf("Coada este goala!");
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
int queue_peek()
{
        return queue[rear];
}

int Stack_isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

int Stack_isFull()
{
    if(top == MAX - 1)
        return 1;
    return 0;
}

void push()
{
    int value;

    if(Stack_isFull() == 1)
    {
        printf("\nStiva este plina!\n");
    }
    else
    {
        printf("Introduceti valoarea pe care vreti s-o adaugati in stiva: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
    
}
void pop()
{
    if(Stack_isEmpty() == 1)
    {
        printf("\nStiva este goala!\n");
    }
    else
    {
        stack[top] = 0;
        top--;
    }
    
}
int stack_peek()
{
        return stack[top];
}
void display_stack()
{
    int i;
    if(Stack_isEmpty() == 1)
    {
        printf("\nStiva este goala, nu exista elemente de afisat!\n");
    }
    else
    {
        printf("Stiva este: ");
        for(i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void display_queue()
{
    int i;
    if(Queue_isEmpty() == 1)
    {
        printf("\nCoada este goala, nu exista elemente de afisat!\n");
    }
    else
    {
        printf("Coada este: ");
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    char x = 'Y';
    int value;


    printf("Se pot executa urmatoarele operatii:\n\n");
    printf("A: Adauga un element la in stiva;\n");
    printf("B: Scoateti ultimul element din stiva;\n");
    printf("C: Afisati ultimul element din stiva;\n");
    printf("D: Verificati daca stiva este goala;\n");
    printf("E: Verificati daca stiva este plina;\n");
    printf("F: Adauga un element la in coada;\n");
    printf("G: Scoateti ultimul element din coada;\n");
    printf("H: Afisati ultimul element din coada;\n");
    printf("I: Verificati daca coada este goala;\n");
    printf("J: Verificati daca coada este plina;\n");
    printf("K: Afisati stiva;\n");
    printf("L: Afisati coada;\n");
    printf("X: Pentru a iesi din program.\n");

    while(x != 'X')
    {
        printf("Introduceti actiunea pe care vreti s-o realizati: ");
        scanf(" %c", &x);
        switch (x)
        {
        case 'A':
            push();
            break;
        case 'B':
            pop();
            break;
        case 'C':
            if(Stack_isEmpty() == 1)
            {
                printf("\nStiva este goala, nu exista elemente de afisat!\n");
            }
            else
            {
                value = stack_peek();
                printf("Ultiul element din stiva este: %d\n", value);
            }
            break;
        case 'D':
            if(Stack_isEmpty() == 1)
                printf("\nStiva este goala!\n");
            else
                printf("\nStiva nu este goala!\n");
            break;
        case 'E':
            if(Stack_isFull() == 1)
                printf("\nStiva este plina!\n");
            else
                printf("\nStiva nu este plina!\n");
            break;
        case 'F':
            Enqueue();
            break;
        case 'G':
            Dequeue();
            break;
        case 'H':
            if(Queue_isEmpty() == 1)
            {
                printf("\nCoada este goala, nu exista elemente de afisat!\n");
            }
            else
            {
                value = queue_peek();
                printf("Ultiul element din coada este: %d\n", value);
            }
            break;
        case 'I':
            if(Queue_isEmpty() == 1)
                printf("\nCoada este goala!\n");
            else
                printf("\nCoada nu este goala!\n");
            break;
        case 'J':
            if(Queue_isFull() == 1)
                printf("\nCoada este plina!\n");
            else
                printf("\nCoada nu este plina!\n");
            break;
        case 'K':
            display_stack();
            break;
        case 'L':
            display_queue();
            break;
        case 'X':
            break;
        default:
            printf("Actiune necunoscuta!\n");
            break;
        }

    }

    return 0;
}