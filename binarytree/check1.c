levelorder(root){
    if(root==NULL){
        return;
    }
    struct node* queue[100];
    rear=-1;
    front=-1;
    rear++;
    queue[rear]=root;
    while(front!=rear){
        struct node* current=queue[++front];
        printf("%d ",current->data);
        if(current->left!-NULL)
        queue[++rear]=current->left;
         if(current->right!-NULL)
        queue[++rear]=current->right;
    }
}
int diameter(struvt node root){
    if(root==NULL){
        return 0;
    }
    int ld=diameter(root->left);
    int rd=diametrr(root->right);
    int h=getheighg(root->left)+getheight(root->right)+1;
    max(ld,rd,h);
}