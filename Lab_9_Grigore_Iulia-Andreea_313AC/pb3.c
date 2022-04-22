#include<stdio.h>
int display_array(int n, int array[10], int i)
{
    
    printf("%d ", array[i]);

    if(i == n - 1)
        return 0;
    else
        return display_array(n, array, i + 1);
        
}
int main()
{
    int i = 0, n = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    printf("Vectorul este:\n");
    display_array(n, array, i);
    printf("\n");

    return 0;
}