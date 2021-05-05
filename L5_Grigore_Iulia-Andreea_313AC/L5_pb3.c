#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}NODE;

NODE *insert_new_node(int data)
{
    NODE *temp_node = (NODE*)malloc(sizeof(NODE));

    temp_node->value = data;
    temp_node->left = NULL;
    temp_node->right = NULL;

    return (temp_node);
}

NODE *ancestor(NODE *root, int n1, int n2)
{
    NODE *left_tree;
    NODE *right_tree;

    if(root == NULL)
        return NULL;

    if ((root->value == n1) || (root->value == n2))
        return root;

    left_tree = ancestor(root->left, n1, n2);
    right_tree = ancestor(root->right, n1, n2);

    if(left_tree && right_tree)
        return root;

    if(left_tree)
        return left_tree;
    else return right_tree;

}

void pre_order(NODE* root)
{
    if(root != NULL) {
        printf("%d ",root->value);
        pre_order(root->left);
        pre_order(root->right);
    }
}

int main()
{

    int n1, n2;
    NODE *x;


    NODE *root = insert_new_node(1);

    root->left = insert_new_node(2);
    root->right = insert_new_node(3);
    root->left->left = insert_new_node(4);
    root->left->right = insert_new_node(5);
    root->left->right->left = insert_new_node(6);
    root->left->right->right = insert_new_node(7);
    root->right->right = insert_new_node(8);

    printf("Arborele este: ");
    pre_order(root);
    printf("\n");
    x = ancestor(root, 4, 7);
    printf("Stramosul comun pentru nodurile 4 si 7 este: %d\n", x->value);

    x = ancestor(root, 8, 4);
    printf("Stramosul comun pentru nodurile 8 si 4 este: %d\n", x->value);

    x = ancestor(root, 6, 7);
    printf("Stramosul comun pentru nodurile 6 si 7 este: %d\n", x->value);

    return 0;

}
