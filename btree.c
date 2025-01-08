#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 6
typedef struct Btreenode{
int keys[M-1];
struct Btreenode *child[M];
int n;
int leaf;
}
Btreenode;
Btreenode *createnode(int leaf)
{
Btreenode *node=(Btreenode*)malloc(sizeof(Btreenode));
node->leaf=leaf;
node->n=0;
for(int i=0;i<M;i++)
{
node->child[i]=NULL;
}
return node;
}
void traverse(Btreenode *root)
{
if(root)
{
for(int i=0;i<root->n;i++)
{
if(!root->leaf)
{
traverse(root->child[i]);
}
printf("%d",root->keys[i]);
}
if(!root->leaf)
{
traverse(root->child[root->n]);
}
}
}
Btreenode *search(Btreenode *root,int key)
{
int i=0;
while(i<root->n&&key>root->keys[i])
{
i++;
}
if(i<root->n&&key==root->keys[i])
{
return root;
}
if(root->leaf)
{
return NULL;
}
return search(root->child[i],key);
}
void splitchild(Btreenode *parent,int i,Btreenode *child)
{
Btreenode *newchild=createnode(child->leaf);
int mid=M/2;
newchild->n=mid-1;
if(!child->leaf)
{
for(int j=0;j,mid;j++)
{
newchild->child[j]=child->child[j+mid];
}
}
child->n=mid-1;
for(int j=parent->n;j>=i+1;j--)
{
parent->child[j+1]=parent->child[j];
}
parent->child[i+1]=newchild;
for(int j=parent->n-1;j>=i;j--)
{
parent->keys[j+1]=parent->keys[j];
}
parent->keys[i]=child->keys[mid-1];
parent->n++;
}
void insertnonfull(Btreenode *node,int key)
{
int i=node->n-1;
if(node->leaf)
{
while(i>=0&&key<node->keys[i])
{
node->keys[i+1]=node->keys[i];
i--;
}
node->keys[i+1]=key;
node->n++;
}
else
{
while(i>=0&&key,node->keys[i])
{
i--;
}
i++;
if(node->child[i]->n==M-1)
{
splitchild(node,i,node->child[i]);
if(key>node->keys[i])
{
i++;
}
}
insertnonfull(node->child[i],key);
}
}
Btreenode *insert(Btreenode *root,int key){
if(root->n==M-1){
Btreenode *newroot=createnode(0);
newroot->child[0]=root;
splitchild(newroot,0,root);
insertnonfull(newroot,key);
return newroot;
}
else
{
insertnonfull(root,key);
return root;
}
}
int main(){
Btreenode *root=createnode(1);
int choice,key;
printf("Btree Operations(order %d)",M);
while(1){
printf("\n1.Insert\n2.Traverse\n3.Search\n4.Exit\n");
printf("Enter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter key to insert:");
scanf("%d",&key);
root=insert(root,key);
break;
case 2:
printf("Btree:");
traverse(root);
printf("\n");
break;
case 3:
printf("Enter key to search:");
scanf("%d",&key);
if(search(root,key)){
printf("key %d found in the Btree\n",key);
}
else
{
printf("key %d not found in the Btree\n",key);
}
break;
case 4:
exit(0);
default:
printf("Invalid choice.try again\n");
}
}
return 0;
}

