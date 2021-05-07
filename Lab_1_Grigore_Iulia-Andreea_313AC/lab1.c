#include<stdio.h>
#include<string.h>

typedef struct informatii
{
  char nume[30];
  char prenume[30];
  char oras[30];
  char liceu[100];
  char v[10][40];
}I;

void afiseaza_datele(I about_me, int n)
{
  int i;


  printf("Datele introduse sunt urmatarele:\n");
  printf("Nume: %s\n",about_me.nume);
  printf("Prenume: %s\n", about_me.prenume);
  printf("Oras: %s\n", about_me.oras);
  printf("Liceu: %s\n", about_me.liceu);

  printf("Hobby-urile sunt:\n");
  for(i = 0; i < n; i++)
  {
    printf("Hobby-ul %d este: %s\n", i + 1, about_me.v[i]);
  }
}

void ordoneaza_hobbies(I about_me, int n)
{
  int i, j;
  char aux[20], x = 'H';

  for(i = 0; i < n; i++)
  {
    for(j = i + 1; j < n; j++)
  {
    if(strcmp(about_me.v[i], about_me.v[j]) > 0)
    {
      strcpy(aux, about_me.v[i]);
      strcpy(about_me.v[i], about_me.v[j]);
      strcpy(about_me.v[j], aux);
    }
  }
 }

 printf("Doriti sa afisati hobby-urile ordonate?(n/y) ");
 scanf("%c", &x);
 if(x == 'y')
 {
   printf("Hobby-urile ordonate sunrt:\n");
   for(i = 0; i < n; i++)
   printf("%s\n", about_me.v[i]);
 }
}

int main()
{
I despre_mine;
int nr = -1;


printf("Introduceti numele: ");
gets(despre_mine.nume);

printf("Introduceti prenumele: ");
gets(despre_mine.prenume);

printf("Introduceti orasul: ");
gets(despre_mine.oras);

printf("Introduceti liceul: ");
gets(despre_mine.liceu);

printf("Introduceti maxim 10 hobbies:\nCand ati terminat, dati ENTER si scrieti done.\n");

  do{
    nr++;
    printf("%d: ",  nr + 1);
    gets(despre_mine.v[nr]);
  }while(strcmp(despre_mine.v[nr], "done")!= 0);


printf("\n");
afiseaza_datele(despre_mine, nr);
ordoneaza_hobbies(despre_mine, nr);

  return 0;
}
