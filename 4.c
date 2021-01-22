#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main()
{
int n,fact1=1,fact2=1,i;
printf("\nEnter the number to check for factorial\n");
scanf("%d",&n);
printf("\nWhen private is not used\n");
#pragma omp parallel for firstprivate(n)
for(i=2;i<=n;i++)

fact1=fact1*i;

printf("\nFactorial is %d",fact1);

printf("\n************************************\n");
printf("\nWhen private is used\n");
#pragma omp parallel for firstprivate(n,fact2)
for(i=1;i<n;i++)

fact2*=i;

printf("\nFactorial is %d",fact2);
}

