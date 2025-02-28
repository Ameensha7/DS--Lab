#include<stdio.h>
#define MAX 100
int parent[MAX];
int rank[MAX];
void makeset(int n)
{
for (int i=0;i<n;i++)
{
parent[i]=i;
rank[i]=0;
}
}
int find(int x)
{
if(parent[x]!=x)
{
parent[x]=find(parent[x]);
}
return parent[x];
}
void unionset(int x,int y)
{
int rootx=find(x);
int rooty=find(y);
if(rootx!=rooty)
{
if(rank[rootx]>rank[rooty])
{
parent[rooty]=rootx;
}
else if(rank[rootx]<rank[rooty])
{
parent[rootx]=rooty;
}
else
{
parent[rooty]=rootx;
rank[rootx]++;
}
printf("Union completed:%d and %d are now in the same set.\n",x,y);
}
else
{
printf("Elements %d and %d are already in the same set.\n",x,y);
}
}
int main(){
int n,choice,x,y;
printf("Enter the number of elements:");
scanf("%d",&n);
makeset(n);
while(1){
printf("\nMenu\n");
printf("1.Find parent of an element\n");
printf("2.Union of two sets\n");
printf("3.Exit\n");
printf("Enter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter element to find its parent:");
scanf("%d",&x);
if(x>=0&&x<n){
printf("parent of %d is:%d\n",x,find(x));
}else{
printf("Invalid element.\n");
break;
case 2:
printf("Enter two elements to perform union:");
scanf("%d%d",&x,&y);
if(x>=0&&x,n&&y>=0&&y,n)
{
unionset(x,y);
}
else{
printf("Invalid elements.\n");
}
break;
case 3:
return 0;
default:
printf("Invalid choice.\n");
}
}
}
}



