void levelorder(struct node*root){
    if(root==NULL){
        return;
    }
    struct node*queue[100];
    int rear=-1;
    int front=-1;
    queue[++rear]=root;
    while(rear!=front){
        struct node*current=queue[++front];
        printf("%d ",current->data);
        if(current->left!=NULL){
            queue[++rear]=current->left;
        }
         if(current->right!=NULL){
            queue[++rear]=current->right;
        }
    }
}
int diameter(struct node*root){
    if(root==NULL){
        return 0;
    }
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    int he=getheight(root->right)+getheight(root->left)+1;
    int max=ld;
    if(rd>max){
        max=rd;
    }
    if(he>max){
        max=he;
    }
    return max;
}