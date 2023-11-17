#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Treenode {
    int val;
    struct Treenode * left;
    struct Treenode *right;

}tree;

// function to create a binary tree
tree* create(int val){
    tree * newnode;
    newnode = (tree*)malloc(sizeof(tree));

    if(newnode == NULL){
        printf("Memory Error\n");
        exit(EXIT_FAILURE);
    }
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    
}

tree *insert(tree * root,int val){
    if(root==NULL){
        return create(val);
    }

    if(val < root->val){
        root->left = insert(root->left,val);
    }else if(val > root->val){
        root->right = insert(root->right,val);
    }
}

void inorder(tree* root){
    if(root==NULL){
        return;

    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void display(tree* root){
    if(root==NULL){
        return;
    }
    
}
int main(void)
{
    tree* root = NULL;

    // Insert values into the binary tree.
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

return 0;
}