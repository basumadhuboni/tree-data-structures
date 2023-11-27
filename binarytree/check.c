#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int key){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//creating tree
struct node* insert(){
    int x;
    struct node* newnode=malloc(sizeof(struct node));
    printf("enter data to be entered or enter -1 for no node");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    newnode->data=x;
    printf("\nenter the left child of %d ",x);
    newnode->left=insert();
    printf("\nenter the right child of %d ",x);
    newnode->right=insert();
    return newnode;
}

// Function to delete a node from binary tree

struct node* deleteNode(struct node* root, int key){
    if (root == NULL)
        return root;
  
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else if(key == root->data){// node is found
        // Node with only one child or no child
        if (root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        // Node with two children
        struct node* minValueNode = root->right;
        while (minValueNode->left != NULL)
            minValueNode = minValueNode->left;
  
        root->data = minValueNode->data;
  
        root->right = deleteNode(root->right, minValueNode->data);
    }
    return root;
}

// Function to print the binary tree (inorder traversal)
void inorderTraversal(struct node* root){
    if (root == NULL)
        return;
  
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
//postorder traversal
void postorder(struct node* root){
   if(root==0){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
      printf("%d ",root->data);
}
//preorder traversal
void preorder(struct node* root){
    if(root==0){
        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    struct node* root = NULL;
    // Inserting nodes into the binary tree
   char ch='y';
    printf("enter the tree\n");
    
         root=insert();
      
    printf("Binary Tree (Inorder traversal): ");
    inorderTraversal(root);
    printf("Binary Tree (preorder traversal): ");
    preorder(root);
    printf("Binary Tree (postorder traversal): ");
    postorder(root);
  
    int key;
    printf("\nEnter the element to delete: ");
    scanf("%d", &key);
  
    // Deleting the specified element
    root = deleteNode(root, key);
  
    printf("Binary Tree after deletion (Inorder traversal): ");
    inorderTraversal(root);
  
    return 0;
}