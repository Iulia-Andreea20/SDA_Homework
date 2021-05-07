#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
} NODE;

NODE *create_a_list(int n)
{
    NODE *head = NULL, *p, *q;
    int i;

    for(i = 0; i < n; i++)
    {
        p = (NODE*)malloc(sizeof(NODE));
        printf("Dati valoarea elementului %d: ", i + 1);
        scanf("%d", &(p->value));
        p->next = NULL;

        if(head == NULL)
            head = p;
        else
        {
            q = head;
            while(q->next!= NULL)
                q = q->next;
            q->next = p;
        }
    }

    return head;
}

void print_the_list(NODE *head)
{
    NODE *p = head;
    printf("Lista cu elemente distincte este: ");
    while(p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}
void delete_duplicates(NODE *head)
{
    NODE *p = head, *q, *x;


    while(p != NULL)
    {
        q = p;
        while(q->next!=NULL)
        {
            if(p->value == q->next->value)
            {

                x = q->next->next;
                free(q->next);
                q->next = x;

            }
            else
                q = q->next;
        }

        p = p->next;
    }
    print_the_list(head);


}
void delete_the_list(NODE *head)
{
    NODE *p, *q;
    p = head;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    printf("Memoria a fost dealocata cu succes!\n");
}
int main()
{

    NODE *head = NULL;
    int n;

    printf("Dati numarul de elemente din lista: ");
    scanf("%d", &n);
    head = create_a_list(n);
    print_the_list(head);
    delete_duplicates(head);
    delete_the_list(head);

    return 0;
}
