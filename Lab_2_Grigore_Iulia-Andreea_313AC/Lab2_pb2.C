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
    printf("Lista este: ");
    while(p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

void verify_if_palindrome(NODE *head, int n)
{
    NODE *p = head;
    int v[100], i= 0, ok = 1;

    while(p != NULL)
    {
        v[i] = p->value;
        p = p->next;
        i++;
    }

    for(i = 0; i < n; i++)
        if(v[i]!= v[n - i - 1])
        {
            ok = 0;
            printf("Lista nu este un palindrom.\n");
            break;
        }
    if(ok == 1)
        printf("Lista este un palindrom.\n");

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
    printf("\nMemoria a fost golita cu succes!");
}
int main()
{

    NODE *head = NULL;
    int n;

    printf("Dati numarul de elemente din lista: ");
    scanf("%d", &n);
    head = create_a_list(n);
    print_the_list(head);
    verify_if_palindrome(head, n);
    delete_the_list(head);

    return 0;
}


