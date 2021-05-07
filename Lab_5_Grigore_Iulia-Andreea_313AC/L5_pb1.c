#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}NODE;

int max(int x, int y)
{
    if(x > y) 
        return x;
    else 
        return y;
}

NODE *insert_new_node(int value)
{
    NODE *temp_node = (NODE*)malloc(sizeof(NODE));

    temp_node->value = value;
    temp_node->left = NULL;
    temp_node->right = NULL;

    return (temp_node);
}

int tree_height(NODE *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(tree_height(node->left), tree_height(node->right));
}

int isBalanced(NODE *node)
{
    int left_height, right_height, height_difference;

    if((node->left == NULL) && (node->right == NULL))
        return 1;

    left_height = tree_height(node->left);
    right_height = tree_height(node->right);

    height_difference = left_height - right_height;

    if(height_difference < 0)
    {
        height_difference *= -1;
    }

    if(height_difference <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return 1;

    return 0;

}

void post_order(NODE* root) 
{
    if(root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->value);
    }
}

int main()
{

    NODE *root1, *root2;


    root1 = insert_new_node(1);
    root2 = insert_new_node(1);

    root1->left = insert_new_node(1);
    root1->right = insert_new_node(2);
    root1->left->left = insert_new_node(3);
    root1->left->right = insert_new_node(4);

    root2->left = insert_new_node(1);
    root2->right = insert_new_node(2);
    root2->left->right = insert_new_node(4);
    root2->left->left->left = insert_new_node(5);
    root2->left->left->left = insert_new_node(6);

    printf("Arborele 1 este: ");
    post_order(root1);
    if(isBalanced(root1))
        printf("\nArborele este echilibrat.\n");
    else
        printf("\nArborele nu este echilibrat.\n");

    printf("Arborele 2 este: ");
    post_order(root2);
    if(isBalanced(root2))
        printf("\nArborele este echilibrat.\n");
    else
        printf("\nArborele nu este echilibrat.\n");
    

    return 0;
}
