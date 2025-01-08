#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node*head=NULL;
struct node*insert(struct node*head,int item)
{
struct node *newnode;
struct node*temp=head;
struct node *temp1=NULL;
int flag=0;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=item;
newnode->prev=NULL;
newnode->next=NULL;
if(head==NULL)
head=newnode;
else if(item<temp->data)
{
temp->prev=insert(temp->prev,item);
return temp;
}
else if(item>temp->data)
{
temp->next=insert(temp->next,item);
return temp;
}
else
{
printf("item already exist");
return temp;
}
}
void inorder(struct node *temp)
{
if(temp!=NULL)
{
inorder(temp->prev);
printf("%d\n",temp->data);
inorder(temp->next);
}
}
void preorder(struct node*temp)
{
if(temp!=NULL)
{
printf("%d\n",temp->data);
preorder(temp->prev);
preorder(temp->next);
}
}
void postorder(struct node*temp)
{
if(temp!=NULL)
{
postorder(temp->prev);
postorder(temp->next);
printf("%d\n",temp->data);
}
}
int main()
{
int choice,item;
printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.exit\n");
while(1){
printf("\nEnter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("\nEnter the item:");
scanf("%d",&item);
head=insert(head,item);
break;
case 2:
printf("inorder\n");
inorder(head);
break;
case 3:
printf("preorder\n");
preorder(head);
break;
case 4:
printf("postorder\n");
postorder(head);
break;
case 5:
exit(0);
break;
default:printf("invalid entry");
} 
}           
}
