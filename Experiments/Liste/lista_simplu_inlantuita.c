#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
   int val;
   struct element *urmator;
}ELEM;

int main()
{
   ELEM *cap_lista, *p, *q;
   int i, nr;


   printf("Numarul de elemente este: ");
   scanf("%d", &nr);

   p = (ELEM*)malloc(sizeof(ELEM));

   if(p == NULL)
   {
      printf("Error!");
      exit(1);
   }

   printf("Tastati valoarea primului element: ");
   scanf("%d", &p->val);

   p->urmator = NULL;
   cap_lista = p;

   for(i = 2; i <= nr; i++)
   {
      q = (ELEM*)malloc(sizeof(ELEM));
      if(q == NULL)
      {
         printf("Error!");
         exit(1);
      }

      printf("Tastati valoarea celui de-al %d element: ", i);
      scanf("%d", &q->val);
      q->urmator = NULL;
      p->urmator = q;
      p = q;
   }

   for(p = cap_lista, i = 1; p != NULL; p = p->urmator, i++)
   {
      printf("Valoarea elementului cu nr %d este %d\n", i, p->val);
   }

   for(p = cap_lista; p!=NULL; p = q)
   {
      q = p->urmator;
      free(p);
   }

   return 0;
   
}

