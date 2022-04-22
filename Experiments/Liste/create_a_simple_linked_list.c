#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}NODE;

void display_the_list(NODE *head)
{
    NODE *p;

    p = head;

    printf("\nThe list is: ");
    while(p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}
NODE *create_a_simple_linked_list(NODE *head)
{
    NODE *p, *q;
    int i, num_nodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    q = (NODE *)malloc(sizeof(NODE));

    printf("Enter the vale of the node 1: ");
    scanf("%d", &data);

    q->value = data;
    q->next = NULL;

    head = q;
    p = head;

    //i incepe de la 1 pt ca am creat deja primul nod, head
    for(i = 1; i < num_nodes; i++)
    {
        
            printf("Enter the vale of the node %d: ", i + 1);
            scanf("%d", &data);

            q = (NODE *)malloc(sizeof(NODE));

            q->value = data;
            q->next = NULL;

            p->next = q;//se face legatura primului nod cu uramtorul
            p = p->next;//priul nod devine al doilea
    }

    return head;
    
}
void dealocate_the_memory(NODE *head)
{
    NODE *p, *q;

    p = head;

    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    } 

    printf("The memory was successfully released!\n");
}
int main()
{
    NODE *head;


    head = create_a_simple_linked_list(head);
    display_the_list(head);
    dealocate_the_memory(head);


    return 0;
}