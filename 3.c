#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
double sines[1000];
int primes[1000];
int i,j,prime,p,z,y,size,w;
void sined(int val1)
{
for(w=0;w<val1;w++)
{
sines[w] = sin(w*M_PI/180);
}
}

void primed(int val2)
{
i=2;
p=0;
while(p<val2)
{ 
prime=1;
for(j=2;j<i;j++)

if(i%j==0)
{
prime=0;
break;
}
if(prime)
{
primes[p]=i;
p++;
}
i++;

}
}









int main()
{
printf("\nEnter the number of primes and sine values required\n");
scanf("%d",&size);
#pragma omp parallel sections
{
#pragma omp section
{
sined(size);
printf("\nThe sine values of %d are:\n",size);
for(y=0;y<size;y++){
printf("%lf\n",sines[y]);
}
}
#pragma omp section
{
primed(size);
printf("\nthe first %d prime  numbers are:\n",size);
for(z=0;z<size;z++){

printf("%d\t",primes[z]);
}
}
}
return 0;
}


