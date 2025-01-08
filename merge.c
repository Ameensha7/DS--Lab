#include<stdio.h>
#include<stdlib.h>
void meregearray(int arr1[],int arr2[],int res[],int s1,int s2)
{
int i=0,j=0,k=0;
while(i<s1&&j<s2)
{
if(arr1[i]<arr2[j])
{
res[k++]=arr1[i++];
}
else{
res[k++]=arr2[j++];
}
while(i<s1)
{
res[k++]=arr1[i++];
}
while(j<s2)
{
res[k++]=arr2[j++];
}
}
}

int main()
{
int i,j,k,s1,s2;
printf("enter the size of 1st array:" );
scanf("%d",&s1);
int *arr1=(int *)malloc(s1*sizeof(int));
printf("enter the %d elements of first sorted array:",s1);
for(int i=0;i<s1;i++)
{
scanf("%d",&arr1[i]);
}
printf("enter the size of 2nd array:" );
scanf("%d",&s2);
int *arr2=(int *)malloc(s2*sizeof(int));
printf("enter the %d elements of second sorted array:",s2);
for(int j=0;j<s2;j++)
{
scanf("%d",&arr2[j]);
}
int *res=(int *)malloc(s1+s2*sizeof(int));
meregearray(arr1,arr2,res,s1,s2);
printf("mereged array:");
for(int k=0;k<s1+s2;k++)
{
printf("%d",res[k]);
}
free(arr1);
free(arr2);
free(res);
return 0;
}





