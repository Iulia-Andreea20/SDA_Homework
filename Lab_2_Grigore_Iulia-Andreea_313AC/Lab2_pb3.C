#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} NODE;

NODE *first_node, *last_node;

void create_a_list(int n)
{
    int i, x;
    NODE *p;

    if(n >= 1)
    {
        first_node = (NODE *)malloc(sizeof(NODE));

        if(first_node != NULL)
        {
            printf(" Introduceti elementul 1 : ");
            scanf("%d", &x);

            first_node->value = x;
            first_node->prev = NULL;
            first_node->next = NULL;
            last_node = first_node;

            for(i = 1; i < n; i++)
            {
                p = (NODE*)malloc(sizeof(NODE));
                if(p != NULL)
                {
                    printf(" Introduceti elementul %d : ", i + 1);
                    scanf("%d", &x);
                    p->value = x;
                    p->prev = last_node;
                    p->next = NULL;

                    last_node->next = p;
                    last_node = p;
                }

            }
        }

    }
}

void search_and_delete()
{
    NODE *p = first_node, *q;
    int x;
    printf("\nCe valoare doriti sa stergeti din lista? ");
    scanf("%d", &x);

    while(p != NULL)
    {
        if(p->value == x && p == first_node)
        {
            first_node = first_node->next;
            first_node->prev = NULL;
            free(p);
            break;
        }
        else if(p->value == x && p == last_node)
        {
            last_node = last_node->prev;
            last_node->next = NULL;
            free(p);
            break;
        }
        else if(p->value == x && p != first_node && p != last_node)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            break;
        }
        p = p->next;
    }
}

void print_the_list()
{
    NODE * p;

    if(first_node == NULL)
    {
        printf(" Lista este goala!");
    }
    else
    {
        p = first_node;
        printf("\nElementele din lista sunt: ");

        while(p != NULL)
        {
            printf("%d ", p->value);
            p = p->next;
        }
    }
}

void delete_the_list()
{
    NODE *p, *q;
    p = first_node;

    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    printf("\nMemoria a fost dealocata cu succes!");
}

int main()
{
    int n;
    first_node = NULL;
    last_node = NULL;

    printf(" Introduceti numarul de elemente : ");
    scanf("%d", &n);

    create_a_list(n);
    print_the_list();
    search_and_delete();
    print_the_list();
    delete_the_list();
    return 0;
}


