#include<stdio.h>
#define MAX_SIZE 8
void display(int set){
printf("{ ");
for(int i=0;i<MAX_SIZE;i++)
{
if(set&(1<<i))
{
printf("%d",i);
}
}
printf(" }-Bit string:");
for (int i=MAX_SIZE-1;i>=0;i--){
printf("%d",(set>>i)&1);
}
printf("\n");
}
int createset(int n){
int set=0,element;
printf("Enter %d element:",n);
for(int i=0;i<n;i++){
scanf("%d",&element);
if(element>=0&&element<MAX_SIZE){
set|=(1<<element);
}
else{
printf("Element %d out of range please enter elements between 0 and %d\n",element,MAX_SIZE-1);
i--;
}
}
return set;
}
int unionset(int setA,int setB){
return setA|setB;
}
int intersectionset(int setA,int setB){
return setA&setB;
}
int differenceset(int setA,int setB){
return setA&~setB;
}
int main(){
int nA,nB;
printf("Enter the number of elements in set A:");
scanf("%d",&nA);
int setA=createset(nA);
printf("Enter the number of elements in set B:");
scanf("%d",&nB);
int setB=createset(nB);
printf("setA:");
display(setA);
printf("setB:");
display(setB);
int Union=unionset(setA,setB);
printf("union of A and B:");
display(Union);
int intersection=intersectionset(setA,setB);
printf("intersection of A and B:");
display(intersection);
int difference=differenceset(setA,setB);
printf("difference of A and B:");
display(difference);
return 0;
}



