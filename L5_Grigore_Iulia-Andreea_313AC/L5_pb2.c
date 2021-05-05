#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value; 
	
    struct node *left;
    struct node *right;

}NODE;

int x[100], j = 0;
NODE *root = NULL;

void insert(int value)
 {
    NODE *tempNode = (NODE*) malloc(sizeof(NODE));
    NODE *current;
    NODE *parent; 


    tempNode->value = value;
    tempNode->left = NULL;
    tempNode->right = NULL;

    if(root == NULL) 
    {
        root = tempNode;
    } 
    else 
    {
        current = root;
        parent = NULL;

        while(1)
        { 
            parent = current;
            if(value < parent->value) 
            {
                current = current->left;                
                if(current == NULL) 
                {
                    parent->left = tempNode;
                    return;
                }
            }  
            else 
            {
                current = current->right;
                if(current == NULL) 
                {
                    parent->right = tempNode;
                    return;
                }
            }
        }            
    }
}

void inorder_traversal(NODE* root) 
{
   if(root != NULL) 
   {
      inorder_traversal(root->left);
      x[j] = root->value;
      j++;        
      inorder_traversal(root->right);
   }
}
int isbinary(int nr_values)
{
    int i;
    for(i = 0; i < nr_values - 1; i++)
            if(x[i] > x[i + 1])
                return 0;
            
    return 1;
}

int main() {
   int i;
   int v[20], nr = 0;

    printf("Introduceti numarul de elemente din arbore: ");
    scanf("%d", &nr);
    
    for(i = 0; i < nr; i++)
    {
        printf("Valoarea elementului %d este: ", i + 1);
        scanf("%d", &v[i]);
    }

    for(i = 0; i < nr; i++)
        insert(v[i]);            

    inorder_traversal(root); 

    if(isbinary(nr) == 1)
        printf("\nArborele este binary search tree!\n");
    else
        printf("\nArborele nu este binary search tree!\n");    

    return 0;
}