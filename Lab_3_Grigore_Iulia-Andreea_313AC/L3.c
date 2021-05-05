#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define MAX 20

int vector[MAX], file_opens;
FILE *file;

void count_lines(int *line)
{
    char aux[100];

    *line = 0;

    if(file_opens == 0)
        if((file = fopen("vector.txt", "rt"))== NULL)
        {
            puts("Fisierul nu se poate deschide!\n");
            exit(1);
        }
    
    while(fgets(aux, sizeof(aux), file))
    {
        (*line)++;
    }  
    
    fclose(file);
}
void read_dates(int *number_of_values)
{
    int i = 0;
    char *p, aux[100];

    *number_of_values = 0;

    if(file_opens == 0)
        if((file = fopen("vector.txt", "rt"))== NULL)
        {
            puts("Fisierul nu se poate deschide!\n");
            exit(1);
        }     
    
    fgets(aux, sizeof(aux), file);
    p = strtok(aux, ",");
    

    while(p)
    {   
        vector[i] = atoi(p);
        i++;
        (*number_of_values)++;
        p = strtok(NULL, ",");
    }

    file_opens++;   

}
void display_vector(int number_of_values, int aux_vector[MAX])
{
    int i;

    printf("Vectorul %d este: ", file_opens);
    for(i = 0; i < number_of_values; i++)
    {
        printf("%d ", aux_vector[i]);
    }
    printf("\n");
}
void copy(int number_of_values, int aux_vector[MAX])
{
    int i;

    for(i = 0; i < number_of_values; i++)
        aux_vector[i] = vector[i];
}
void swap(int *nr1, int *nr2)
{
    int aux;
    
    aux = *nr1;
    *nr1 = *nr2;
    *nr2 = aux;
}
void bubble_sort(int number_of_values)
{
    int i, j, aux_vector[MAX];
    long before, after;
    double elapsed;

    copy(number_of_values, aux_vector);
    before = clock();
    for(i = 0; i < number_of_values; i++)
        {
            for(j = i + 1; j < number_of_values; j++)
            {
                if(aux_vector[i] > aux_vector[j])
                {
                    swap(&aux_vector[i], &aux_vector[j]);
                }
            }
        }

    after = clock();
    elapsed = (double)(after - before)/CLOCKS_PER_SEC;
    printf("Timpul de rulare pentru Bubble Sort este: %lf\n", elapsed);
   
    display_vector(number_of_values, aux_vector);


        
}

void insertion_sort(int number_of_values)
{
    int i, j, aux, aux_vector[MAX];
    long before, after;
    double elapsed;

    copy(number_of_values, aux_vector);
    before = clock();
    for(i = 0; i < number_of_values; i++)
    {
        aux = aux_vector[i];
        j = i - 1;

        while(j >= 0 && aux_vector[j] > aux)
        {
            aux_vector[j + 1] = aux_vector[j];
            j--;
        }
        aux_vector[j + 1] = aux;
    }
    after = clock();
    elapsed = (double)(after - before)/CLOCKS_PER_SEC;
    printf("Timpul de rulare pentru Insertion Sort este: %lf\n", elapsed);
   
    display_vector(number_of_values, aux_vector);
}

void selection_sort(int number_of_values)
{
    int i, j, min, aux_vector[MAX];
    long before, after;
    double elapsed;

    copy(number_of_values, aux_vector);
    before = clock();
    for(i = 0; i < number_of_values - 1; i++)
    {
        min = i;
        for(j = i + 1; j < number_of_values; j++)
        {
            if(aux_vector[j] < aux_vector[min])
            {
                min = j;
            }
        }

        swap(&aux_vector[min], &aux_vector[i]);
    }
    after = clock();
    elapsed = (double)(after - before)/CLOCKS_PER_SEC;
    printf("Timpul de rulare pentru Selection Sort este: %lf\n", elapsed);
   
    display_vector(number_of_values, aux_vector);
}

void merge(int aux_vector[MAX], int left, int mid, int right)
{
    int aux[MAX], i, j, pivot;

    i = left;
    j = mid + 1;
    pivot = left;

    while(i <= mid && j <= right)
    {
        if(aux_vector[i] < aux_vector[j])
        {
            aux[pivot] = aux_vector[i];
            pivot++;
            i++;
        }
        else
        {
            aux[pivot] = aux_vector[j];
            pivot++;
            j++;
        }
    }

    while (i <= mid)
    {
        aux[pivot] = aux_vector[i];
        pivot++;
        i++;
    }
    while (j <= right)
    {
        aux[pivot] = aux_vector[j];
        pivot++;
        j++;
    }
    for (i = left; i < pivot; i++)
    {
        aux_vector[i] = aux[i];
    }
   
}

void merge_sort(int aux_vector[MAX], int left, int right)
{

    int mid;

    if(left < right)
    {
        mid = (left + right)/2;

        merge_sort(aux_vector, left, mid);
        merge_sort(aux_vector, mid + 1, right);

        merge(aux_vector, left, mid, right);

    }  
    return;        
     
}

int partition(int aux_vector[MAX], int left, int right)
{
    int pivot = aux_vector[right];
    int part = left;
    int i;

    for(i = left; i < right; i++)
    {
        if(aux_vector[i] <= pivot)
        {
            swap(&aux_vector[i], &aux_vector[part]);
            part++;
        }
    }

    swap(&aux_vector[part], &aux_vector[right]);

    return part;
}
void quick_sort(int aux_vector[MAX], int left, int right)
{
    int part;
    if(left < right)
    {
        part = partition(aux_vector, left, right);
        quick_sort(aux_vector, left, part - 1);
        quick_sort(aux_vector, part + 1, right);
    }
}



int main()
{
    int nr_values, line, aux_vector[MAX]; 
    int left, right;
    long before, after;
    double elapsed;
    

    count_lines(&line); 
    
    while(line)
    {
        read_dates(&nr_values);
        display_vector(nr_values, vector);
        left = 0, right = nr_values - 1;


        printf("Dupa ordonarea crescatoare a sirului cu Bubble Sort:\n");
        bubble_sort(nr_values);

        printf("\nDupa ordonarea crescatoare a sirului cu Insertion Sort:\n");
        insertion_sort(nr_values);

        printf("\nDupa ordonarea crescatoare a sirului cu Selection Sort:\n");
        selection_sort(nr_values);

        printf("\nDupa ordonarea crescatoare a sirului cu Merge Sort:\n");
        copy(nr_values, aux_vector);

        before = clock();
        merge_sort(aux_vector, left, right);
        after = clock();
        elapsed = (double)(after - before)/CLOCKS_PER_SEC;
    
        display_vector(nr_values, aux_vector);
        printf("Timpul de rulare pentru Merge Sort este: %lf\n", elapsed);

        printf("\nDupa ordonarea crescatoare a sirului cu Quick Sort:\n");
        copy(nr_values, aux_vector);

        before = clock();
        quick_sort(aux_vector, left, right);
        after = clock();
        elapsed = (double)(after - before)/CLOCKS_PER_SEC;

        display_vector(nr_values, aux_vector);
        
        printf("Timpul de rulare pentru Quick Sort este: %lf\n", elapsed);
   
        printf("\n\n\n");

        line--;
    }
    
    fclose(file);

    return 0;
}
