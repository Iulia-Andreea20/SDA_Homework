#include<stdio.h>

int fibonacci_recursiv(n)
{
    if (n <= 1)
        return 1;
    else
        return fibonacci_recursiv(n - 1) + fibonacci_recursiv(n - 2);
}

int fibonacci_iterativ(n)
{
    int i, nr_1 = 1, nr_2 = 1, fibo = 0;
    

    for (i = 2; i < n + 1; i++)
    {
        fibo = nr_1 + nr_2;
        nr_1 = nr_2;
        nr_2 = fibo;
    }

    
    return fibo;
}

int main()
{   
    int n = 10;


    printf("Fibonacci recursiv:\n");
    printf("Al %d-lea termen al sirului Fibonacci este: %d\n\n", n, fibonacci_recursiv(10));

    printf("Fibonacci iterativ:\n");
    printf("Al %d-lea termen al sirului Fibonacci este: %d\n", n, fibonacci_iterativ(10));


    return 0;
}