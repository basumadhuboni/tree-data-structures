#include <stdio.h>  
#include <stdlib.h>  
 int s,v;  
struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  
struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  //new node is initialized with height 1
    return node;  //returns address of the newly created node
}  
 int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  

int max (int a, int b){  
    return (a>b)?a:b;  
}  
   
int getBalanceFactor(struct Node * n){ //returns height of left subtree-height of right subtree
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right); 
}  
   
struct Node* rightRotate(struct Node* y){  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return x;  
}  
   
struct Node* leftRotate(struct Node* x){  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return y;  //returns the new node
}  
 //findinf inorder predecessor
 struct Node* inorder_predecessor(struct Node* root){
    root=root->left;
   while(root->right!=NULL){
    root=root->right;
   }
   return root;
}

struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  //creating a new node 
   
    if (key < node->key)  
        node->left  = insert(node->left, key);//returns address of the left child which gets stored in node->left
    else if (key > node->key)  
        node->right = insert(node->right, key);//returns address of right child which gets stored in node->right  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  
   
    // Left Left Case (the new key is inserted as left child of left sub tree of that node)
        if(bf>1 && key < node->left->key){  
            return rightRotate(node);  
        }  
    // Right Right Case (the new key is inserted as right child of right sub tree of that node)
        if(bf<-1 && key > node->right->key){  
            return leftRotate(node);  
        }  
    // Left Right Case (new key is inserted in the right subtree of the left child).
    if(bf>1 && key > node->left->key){  
            node->left = leftRotate(node->left); //the tree now becomes left left 
            return rightRotate(node);  
        }  
    // Right Left Case (the new key is inserted as left child of right sub tree of that node)
    if(bf<-1 && key < node->right->key){  
            node->right = rightRotate(node->right); //tree bnow becomes right right
            return leftRotate(node);  
        }  
    return node;  
}  
           //********DELETING NODE FROM TREE**********

   struct Node* deleteNode(struct Node* root, int key){
    //performing standard bst search
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
    else//the node to be deleted has been found
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
    struct Node *temp = root->left ? root->left : root->right;//the non empty child's address is stored in temp
             // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; //that child now becomes the root
            free(temp);
        }
        else // node with two children
        {
            struct Node* ipre=inorder_predecessor(root);
      root->key=ipre->key;
      root->left=deleteNode(root->left,ipre->key);
        }
    }
     // If the tree had only one node then return
    if (root == NULL)
      return root;
     //  UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
 
    // GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
   int bf = getBalanceFactor(root);  
   
    // Left Left Case (the new key is inserted as left child of left sub tree of that node)
        if(bf>1 && key < root->left->key){  
            return rightRotate(root);  
        }  
    // Right Right Case (the new key is inserted as right child of right sub tree of that node)
        if(bf<-1 && key > root->right->key){  
            return leftRotate(root);  
        }  
    // Left Right Case (new key is inserted in the right subtree of the left child).
    if(bf>1 && key > root->left->key){  
            root->left = leftRotate(root->left); //the tree now becomes left left 
            return rightRotate(root);  
        }  
    // Right Left Case (the new key is inserted as left child of right sub tree of that node)
    if(bf<-1 && key < root->right->key){  
            root->right = rightRotate(root->right); //tree bnow becomes right right
            return leftRotate(root);  
        }  
    return root;//returns root of the modified tree
}
void preOrder(struct Node *root)  // preorder traversal and display
{  
    if(root != NULL)  
    {  
        printf("%d ", root->key); 
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
// searching element

void search(struct Node *root)  //  SEARCHING
{  
    if(root != NULL)  
    {  
        if(root->key==v){
            s=1;
        } 
        search(root->left);  
        search(root->right);  
    }  
}  
   
int main(){  
    struct Node * root = NULL;  
    char t = 'y';
   int a,ch,d;
    while (t == 'y') {
        printf("1 for adding, 2 for deletion, 3 for searching 4.display\n");
        scanf("%d", &ch);
        if (ch == 1) {
              printf("enter the numberb to be added");
              scanf("%d",&a);
               root=insert(root,a);
            }
         else if (ch == 2) 
         {
          printf("enter the numberb to be deleted");
              scanf("%d",&d);
              root = deleteNode(root, d);  
        } 
        else if (ch == 3) 
        {
            printf("enter the numberb to be searched");
              scanf("%d",&v);
           s=0;
           search(root);
           if(s==1){
            printf("elemnt is present\n");
           }
           else if(s==0){
            printf("element not present\n");
           }
        } 
        else if(ch == 4)
        {
             preOrder(root); 
        }
        printf("Do you want to perform more operations? (y/n): \n");
        scanf(" %c", &t);
    }
    return 0; 
}  