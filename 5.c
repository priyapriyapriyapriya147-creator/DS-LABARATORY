#include<stdio.h>
#include<stdlib.h>
struct node{
int key;
struct node*left,*right;
};
struct node*createnode(int key){
struct node*newnode=(struct node*)malloc(sizeof(struct node));
newnode->key=key;
newnode->left=newnode->right=NULL;
return newnode;
}
struct node*insert(struct node*root,int key){
if(root==NULL)
return createnode(key);
if(key<root->key)
root->left-insert(root->left,key);
else if(key>root->key)
root->right=insert(root->right,key);
return root;
}
struct node*search(struct node*root,int key){
if(root==NULL||root->key==key)
return root;
if(key<root->key)
return search(root->left,key);
else
return search(root->right,key);
}
struct node*findmin(struct node*root){
if(root == NULL) 
return NULL;
while(root->left != NULL)
root=root->left;
return root;
}
struct node*findmax(struct node*root){
if(root == NULL)
return NULL;
while(root->right != NULL)
root = root->right;
return root;
}
struct node*deletenode(struct node*root,int key){
if(root == NULL)
return root;
if(key<root->key)
root->left=deletenode(root->left,key);
else if(key>root->key)
root->right=deletenode(root->right,key);
else{
if(root->left==NULL && root->right == NULL){
free(root);
return NULL;
}
else if(root->left == NULL){
struct node*temp=root->right;
free(root);
return temp;
}
else if(root->right == NULL){
struct node*temp=root->left;
free(root);
return temp;
}
struct node*temp=findmin(root->right);
root->key=temp->key;
root->right=deletenode(root->right,temp->key);
}
return root;
}
void inorder(struct node*root){
if(root != NULL){
inorder(root->left);
printf("%d",root->key);
inorder(root->right);
}
}
int main(){
struct node*root=NULL;
int choice,key;
struct node*temp;
while(1){
printf("\n---Binary search tree menu---\n");
printf("1.insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.find minimum\n");
printf("5.Find maximum\n");
printf("6.Display (inorder)\n");
printf("7.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("enter key to insert:");
scanf("%d",&key);
root=insert(root,key);
break;
case 2:
printf("enter key to delete:");
scanf("%d",&key);
root=deletenode(root,key);
break;
case 3:
printf("Enter key to search:");
scanf("%d",&key);
temp=search(root,key);
if(temp!= NULL)
printf("key %d found in BST.\n",key);
else
printf("Key %d not found in BST.\n",key);
break;
case 4:
temp=findmin(root);
if(temp != NULL)
printf("minimum key =%d\n",temp->key);
else
printf("tree is empty.\n");
break;
case 5:
temp=findmax(root);
if(temp != NULL)
printf("Maximum key =%d\n",temp->key);
else
printf("tree is empty.\n");
break;
case 6:
printf("inorder traversal:");
inorder(root);
printf("\n");
break;
case 7:
exit(0);
default:
printf("invalid choice!\n");
}
}
}

