#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
// creating a new node
struct node *createnode(int key){  
     struct node* newnode = (struct node*) malloc(sizeof(struct node));  
    newnode->data = key;  
    newnode->left = NULL;  
    newnode->right = NULL;
    return newnode;  //returns address of the newly created node
}  
//inserting element in binary search tree
struct node* insert(struct node* root,int d){
    if (root == NULL)  
        return  createnode(d);  //creating a new node 
   
    if (d < root->data)  
        root->left  = insert(root->left,d);
    else if (d > root->data)  
        root->right = insert(root->right,d);
    return root;
}
struct node* inorder_predecessor(struct node* root){ // finding inorder predecessor
   root=root->left;
   while(root->right!=NULL){
    root=root->right;
   }
   return root;
}
struct node* deletenode(struct node* root,int value){
    struct node* ipre;
   if(root==NULL){
    return root;
   }
   if(root->left==NULL && root->right==NULL){//leaf node
    return NULL;
   }
   else if(root->left==NULL){// node with no left child
        return root->right;
   }
   else if(root->right==NULL){// node with no right child
       return root->left;
   }
   if(value<root->data){
    root->left=deletenode(root->left,value);
   }
   else if(value>root->data){
    root->right=deletenode(root->right,value);
   }
   else{    //value is found
      ipre=inorder_predecessor(root);
      root->data=ipre->data;
      root->left=deletenode(root->left,ipre->data);
   }
   return root;
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
void main(){
    int d,a;
    char ch='y';
    struct node* root=NULL;
    printf("enter the first tree\n");
    while(ch=='y'){
        printf("enter the number to be inserted");
        scanf("%d",&a);
       root=insert(root,a);
       printf("do you want to enter more nodes? y/n");
       scanf(" %c",&ch);
    }
     printf("\nthe preorder traversal is");
    preorder(root);
    printf("\nenter the value to be deleted");
    scanf("%d",&d);
    root=deletenode(root,d);
    printf("\nthe preorder traversal is");
    preorder(root);
}