#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node *top=0;
void push()
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&newnode->data);
newnode->link=0;
if(top==0){
top=newnode;
}
else{
newnode->link=top;
top=newnode;
}
}
void display()
{
struct node *temp;
temp=top;
if(top==0){
printf(" stack is empty");
}
else
{
while(temp!=0)
{
printf("%d\n",temp->data);
temp=temp->link;
}
}
}
void peek()
{
if(top==0)
{
printf("stack is empty");
}
else
{
printf("top element is %d",top->data);
}
}
void pop()
{
struct node *temp;
temp=top;
if(top==0)
{
printf("stack is empty");
}
else
{
top=temp->link;
printf("deleted item is %d",temp->data);
free(temp);
}
}
int main()
{
int choice;
while(1){
printf("\noperations:\n1.push\n2.display\n3.peek\n4.pop\n5.exit\n");
printf("Enter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:
push();
break;
case 2:
display();
break;
case 3:
peek();
break;
case 4:
pop();
case 5:
exit(0);
break;
default:printf("invalid entry");
} 
}           
}



