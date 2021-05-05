#include<stdio.h>
#define MAX 20

int v[MAX], n;
int top1, top2;

void empty_starck1()
{
    int x;

    if(top1 >= 0)
     {
        while(top1 >= 0)
        {
            v[top1] = 0;
            top1--;
        }         
     }
     else
     {
         printf("\nStiva 1 este deja goala!\n"); 
     } 

    
}
void empty_starck2()
{
    int x;

    if(top2 < n)
        {
            while(top2 < n)
                {
                    v[top2] = 0;
                    top2++;
                }
        }
        else
        {
            printf("\nStiva 2 este deja goala!\n");
        }  

    
}
void display_array()
{
    int i;
    printf("Vectorul este: ");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}
void display_starck1()
{
    int i;

    printf("\nStiva 1 este: ");
    if(top1 >= 0)
    {
        for(i = 0; i <= top1; i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
     else
    {
        printf("\nStiva 1 este goala!\n");
    } 
}
void display_starck2()
{
    int i;

    printf("\nStiva 2 este: ");
    if(top2 < n)
    {
        for(i = n - 1; i >= top2; i--)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
     else
    {
        printf("\nStiva 2 este goala!\n");
    } 
}
void push1()
{
    int value;

    if(top1 < top2 - 1)
    {
        printf("Introduceti valoare elementului pe care vreti sa-l adaugati: ");
        scanf("%d", &value);
        
        top1++;
        v[top1] = value;
    }
    else
    {
        printf("\nVectorul este plin! Nu mai puteti adauga elemente in stiva 1!\n");
    }   

}
void push2()
{
    int value;

    if(top1 < top2 - 1)
    {   
        printf("Introduceti valoare elementului pe care vreti sa-l adaugati: ");
        scanf("%d", &value);
        top2--;
        v[top2] = value;
    }
    else
    {
        printf("\nVectorul este plin! Nu mai puteti adauga elemente in stiva 2!\n");
    }   

}
void pop1()
{
    if(top1 >= 0)
    {
        v[top1] = 0;
        top1--;
    }
    else
    {
        printf("\nStiva este goala!\n");
    }  
}
void pop2()
{

    if(top2 < n)
    {
        v[top2] = 0;
        top2++;
    }
    else
    {
        printf("\nStiva este goala!\n");
    }  
}
int main()
{
    char x = 'Y';

    printf("Introduceti lungimea vectorului (un numar mai mic decat 20): ");
    scanf("%d", &n);
    if(n > 20)
    {
        while(n > 20)
        {
            printf("Numarul de elemente este prea mare, introducei un numar mai mic decat 20.");
            printf("Introduceti lungimea vectorului: ");
            scanf("%d", &n);
        }
    }

    top1 = -1;
    top2 = n;
    
    printf("\nPuteti realiza urmatoarele actiuni:\n\n");
    printf("A : Introduceti un element in stiva 1;\n");
    printf("a : Introduceti un element in stiva 2;\n");
    printf("P: Stergeti ultimul element din stiva 1;\n");
    printf("p: Stergeti ultimul element din stiva 2;\n");
    printf("S: Afisati stiva 1;\n");
    printf("s: Afisati stiva 2;\n");
    printf("E: Goliti stiva 1\n");
    printf("e: Goliti stiva 2\n");
    printf("D: Afisati vectorul in care sunt stocate cele 2 stive.\n");
    printf("X: Pentru a iesi din program\n\n");

    while(x != 'x')
    {
        printf("Introduceti o actiune(A/a/P/p/S/s/E/e/D/x): ");
        scanf(" %c", &x);

        switch (x)
        {
        case 'A':
            push1();
            break;
        case 'a':
            push2();
            break;
        case 'P':
            pop1();
            break;
        case 'p':
            pop2();
            break;
        case 'S':
            display_starck1();
            break;
        case 's':
            display_starck2();
            break;
        case 'E':
            empty_starck1();
            break;
        case 'e':
            empty_starck2();
            break;
        case 'D':
            display_array();
        case 'x':
            break;
        default:
            printf("\nActiune necunoscuta.\n");
            break;
        }
    }


    return 0;
}