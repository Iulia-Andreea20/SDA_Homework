#include<stdio.h>
#define MAX_WEIGHT 50


int max(int x, int y) 
{
   if(x > y)
   {
      return x;
   } 
   else 
   {
      return y;
   }
}

//Metoda iterativa
// int knapsack(int weight[], int value[], int elements) 
// {
//    int i, j;
//    int knap[elements + 1][MAX_WEIGHT + 1];
//
//
//    for (i = 0; i <= elements; i++) 
//    {
//       for (j = 0; j <= MAX_WEIGHT; j++) 
//       {
//          if (i == 0 || j == 0)
//          {
//             knap[i][j] = 0;
//          }   
//          else if (weight[i - 1] <= j)
//          {
//             knap[i][j] = max(value[i - 1] + knap[i - 1][j - weight[i - 1]], knap[i - 1][j]);
//          }
//          else
//          {
//             knap[i][j] = knap[i - 1][j];
//          }
//       }
//    }
//    return knap[elements][MAX_WEIGHT];
// }

//Metoda recursiva
int knapsack(int MAX_W, int weight[], int value[], int elements)
{
    
   if (elements == 0 || MAX_W == 0)
   {
      return 0;
   }
      
   if (weight[elements - 1] > MAX_W)
   {
      return knapsack(MAX_W, weight, value, elements - 1);
   }
   else
   {
      return max(value[elements - 1] + knapsack(MAX_W - weight[elements - 1], weight, value, elements - 1), knapsack(MAX_W, weight, value, elements - 1));
   }
      
}

int main() 
{
   int value[] = {20, 25, 25, 60, 30};
   int weight[] = {25, 20, 30, 25, 30};
   int MAX_W = MAX_WEIGHT;


   int elements = sizeof(value)/sizeof(value[0]);
   printf("Valoarea maxima este : %d \n", knapsack(MAX_W, weight, value, elements));


   return 0;
}