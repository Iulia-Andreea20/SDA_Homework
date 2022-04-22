#include<stdio.h>
#include<stdlib.h>

#define muchii 6
#define INFINITY 1000

typedef struct comanda
{
    int cost;
}COMANDA;

typedef struct node 
{ 
    int val;
    struct node *left, *right; 
}NODE; 
   

NODE* nod_nou(int valoare) 
{ 
    NODE* aux =  (NODE*)malloc(sizeof(NODE)); 
    aux->val = valoare; 
    
    aux->left = aux->right = NULL; 
    return aux; 
} 
   

NODE* inserare(NODE* node, int cost) 
{ 
    
    if (node == NULL) 
    {
        return nod_nou(cost);
    }
         
  
    if (cost < node->val) 
    {
        node->left  = inserare(node->left, cost); 
    }
    else if (cost > node->val) 
    {
        node->right = inserare(node->right, cost);
    }    
  
    return node; 
} 
   
void initializare_comenzi(COMANDA comanda[6])
{
    comanda[0].cost = 10;
    comanda[1].cost = 12;
    comanda[2].cost = 11;
    comanda[3].cost = 15;
    comanda[4].cost = 13;
    comanda[5].cost = 9;

}

void afiseaza_comenzi(COMANDA comanda[6])
{
    int i;

    for(i = 0; i < 6; i++)
    {
        printf("%d ", comanda[i].cost);   
    }

}

void ordoneaza_dupa_pret(COMANDA arbore[6])
{
    COMANDA aux;
    int i, j;

    for(i = 0; i < 6; i++)
    {
        for(j =  i + 1; j < 6; j++)
        {
            if(arbore[i].cost < arbore[j].cost)
            {
                aux.cost = arbore[i].cost;
                arbore[i].cost = arbore[j].cost;
                arbore[j].cost = aux.cost;
            }
        }
    }
}

void Preorder(struct node* node)
{
    if (node == NULL)
    {
        return;
    }
 
    printf("%d ", node->val);
    Preorder(node->left);
    Preorder(node->right);
}


// Functie pentru a gasi muchia cu valoarea cea mai mica, dintre cele existente
int distanta_minima(int distanta[], int ok_path[])
{
	int min = INFINITY, poz_min;
    int i;

	for (int i = 0; i < muchii; i++)
    {
        if (ok_path[i] == 0 && distanta[i] <= min)
        {
            min = distanta[i];
            poz_min = i;
        }
    }		

	return poz_min;
}

// Afisarea valorilor nodurilor si a vectorului de distante
void afiseaza_rezultat(int distanta[], int n, COMANDA comanda[6])
{
	printf("Distanta de la nodul sursa, la celelalte noduri este:\n\n");
	for (int i = 0; i < muchii; i++)
    {
        printf("Distanta de la nodul %d, la nodul %d, este de: %d\n",comanda[0].cost, comanda[i].cost, distanta[i]);
    }
}

// Dijkstra aplicata asupra unei matrice de adiacenta
void dijkstra(int graph[muchii][muchii], int sursa, COMANDA comanda[6])
{
	int distanta[muchii];
	int ok_path[muchii];
    int i, j;

	// Initializare toate distantele cu infinit
	for (int i = 0; i < muchii; i++)
    {
        distanta[i] = INFINITY;
        ok_path[i] = 0;
    }

	// Distanta de la sursa, la ea insasi este 0
	distanta[sursa] = 0;

	// Gasirea celui mai scurt drum de la sursa, la toate celelalte noduri
	for (int count = 0; count < muchii - 1; count++) 
    {

		j = distanta_minima(distanta, ok_path);

		// Marcheaza nodul vizitat cu ok
		ok_path[j] = 1;

		for (i = 0; i < muchii; i++)
        {
            if (!ok_path[i] && graph[j][i] && distanta[j] != INFINITY && distanta[j] + graph[j][i] < distanta[i])
            {
                distanta[i] = distanta[j] + graph[j][i];
            }
        }

	}

	// Afiseaza nodurile si distanta de la sursa, pana la ele
	afiseaza_rezultat(distanta, muchii, comanda);
}
int main()
{
    COMANDA comanda[6];
    NODE *root = NULL;
    int i;
    int graph[muchii][muchii] = { { 0, 5, 0, 0, 0, 0},
						          { 5, 0, 3, 0, 0, 0},
						          { 0, 3, 0, 9, 0, 3},
						          { 0, 0, 9, 0, 2, 7},
						          { 0, 0, 0, 2, 0, 11},
						          { 0, 0, 3, 7, 11, 0},};



    printf("\nValorile initiale sunt: ");
    initializare_comenzi(comanda);
    afiseaza_comenzi(comanda);
    printf("\n");


    printf("Valorile arborelui, parcurs Pre-order: ");
    root = inserare(root, comanda[0].cost);
    for(i = 0; i < 6; i++)
    {
        inserare(root, comanda[i].cost);
    }

    Preorder(root);
    printf("\n");

    printf("Valorile comenzilor, ordonate descrescator: ");
    ordoneaza_dupa_pret(comanda);
    afiseaza_comenzi(comanda);
    printf("\n");


    dijkstra(graph, 0, comanda);
    

    return 0;
}