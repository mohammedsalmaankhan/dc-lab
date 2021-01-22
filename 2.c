#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main()
{
int ncol,nrow,i,j;
printf("\nEnter the number of rows and columns of the matrix\n");
scanf("%d%d",&nrow,&ncol);
int matrix[nrow][ncol],result[nrow],vector[ncol];
for(i=0;i<nrow;i++)
for(j=0;j<ncol;j++)
matrix[i][j]=i+j;
for(i=0;i<nrow;i++)
result[i]=0;
for(j=0;j<ncol;j++)
vector[j]=j;
printf("\nThe matrix is \n");
for(i=0;i<nrow;i++){
for(j=0;j<ncol;j++){
printf("%d\t",matrix[i][j]);
}
printf("\n");
}
printf("\nthe vector is :\n");
for(j=0;j<ncol;j++)
printf("%d\t",vector[j]);
//printf("\nThe result is :\n");
omp_set_num_threads(32);
#pragma omp parallel private(j)
for(i=0;i<nrow;i++){
for(j=0;j<ncol;j++) {
result[i]+=matrix[i][j]*vector[j];
}
}
printf("\nthe result is \n");
for(i=0;i<nrow;i++)
printf("%d\t",result[i]);
}


