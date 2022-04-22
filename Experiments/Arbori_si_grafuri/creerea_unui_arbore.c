#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data_element;
    struct node *left, *right;
}NODE;


NODE *create_new_node_in_tree(int data_element)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE)); // Allocating memory to the node
    temp->data_element = data_element;
    temp->left = temp->right = NULL;
    return temp;
}


NODE* insert_a_node_into_a_tree(struct node* node, int data_element)
{

if (node == NULL) 
    return create_new_node_in_tree(data_element); 

if (data_element < node->data_element)
    {
        node->left = insert_a_node_into_a_tree(node->left, data_element);
    }
else if (data_element > node->data_element)
    {
        node->right = insert_a_node_into_a_tree(node->right, data_element);
    }

return node;
}
void display(NODE *root) 
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data_element);
        display(root->right);
    }
}

void delete_tree(NODE *root)
{
    if(root == NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->right);

    free(root);
}

void create_tree(NODE *root)
{
    int i, nr_nodes, value;

    printf("Introduceti numarul de noduri: ");
    scanf("%d", &nr_nodes);

    for(i = 0; i < nr_nodes; i++)
    {
        printf("Introduceti valoarea nodului %d: ", i + 1);
        scanf("%d", &value);

        if(i == 0)
            {
                root = insert_a_node_into_a_tree(root, value);
            }
        else
            {
                insert_a_node_into_a_tree(root, value);
            }
    }
}

int main()
{
    NODE *root = NULL;
    
    create_tree(root);
    printf("Arborele este: ");
    display(root);
    printf("\n");
    delete_tree(root);

    return 0;
}