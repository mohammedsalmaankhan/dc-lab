#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int i,n;
void merge(int a[],int x1,int y1,int x2,int y2)
{
int p=x1;
int q=x2;
int k=0;
int temp[1000];
while(p<=y1 && q<=y2){
if(a[p]<a[q])
temp[k++]=a[p++];
else
temp[k++]=a[q++];
}
while(p<=y1)
{
temp[k++]=a[p++];
}
while(q<=y2)
{
temp[k++]=a[q++];
}

for(int i=x1,j=0;i<=y2;i++,j++)
a[i]=temp[j];
}


void mergesort(int a[],int p,int q)
{
int mid;
if(p<q)
{
mid=(p+q)/2;
#pragma omp parallel sections
{
#pragma omp section
{
mergesort(a,p,mid);
}
#pragma omp section
{
mergesort(a,mid+1,q);
}
}
merge(a,p,mid,mid+1,q);
}
}


void main()
{

printf("\nEnter the number of elements\n");
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
{
a[i]=rand()%100;
}
printf("\nThe Unsorted elements are\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
printf("\n");
}
mergesort(a,0,n-1);
printf("\nThe sorted elements are\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
printf("\n");
}
}
