//Gauss-Elimination
#include <stdio.h>
#include <stdlib.h>
void swap(double *row1, double *row2, int u)		//To swap row1 with row2
{
int temp, j;
for(j=0 ; j<u ; j++)
{
temp = *(row1+j);
*(row1+j) =*(row2+j);
*(row2+j) = temp;
}
}
int main()
{
int u,e,i,j,k,e_eff,eb;
double **a, *b, mul, *x;
label:
printf("Enter no. of unknowns:");
scanf("%d",&u);										//Scanning no. of unknowns
printf("Enter no. of equations:");
scanf("%d",&e);										//Scanning no. of equations
/*if(e < u)
{
printf("No. of equations should be more than or equal to no. of unknowns. Please enter valid values.");
goto label;										//In case of inconsistent data
}*/
a = (double **) malloc(sizeof(double) * e);			//For coefficients of unknowns
b = (double *) malloc(sizeof(double) * e);			//For constants in the equations
x = (double *) malloc(sizeof(double) * u);			//For unknowns
for(i=0;i<e;i++)
{
*(a+i) = (double *) malloc(sizeof(double) * u);
}
printf("Enter the data:\n");
for(i=0;i<e;i++)
{
for(j=0;j<u;j++)
{
printf("a%d%d:",i+1,j+1);
scanf("%lf",&a[i][j]);
}
printf("b%d:",i+1);
scanf("%lf",&b[i]);
}
for(i=0 ; i<e ; i++)							//For every unknown
{
if(a[i][i] == 0)							//Checking if pivot-element in the pivot row is zero
{
for(j=i+1 ; a[j][i]==0 && j<e; j++);	//Searching first row after current pivot row with non-zero pivot value
if(j==e)								//If pivot element of every row is zero, check for next unknown
continue;
else
{										//Swap the rows
swap(*(a+j),*(a+i),u);
b[i] = b[j] + b[i];
b[j] = b[i] - b[j];
b[i] = b[i] - b[j];
}
}
for(j=i+1 ; j<e ; j++)						//for every row after the pivot row
{
mul = a[j][i] / a[i][i];				//multiplicator
for(k=0 ; k<u ; k++)					//Subtracting pivot row from each row after it
{
a[j][k] -= mul * a[i][k];
}
b[j] -= b[i]*mul;
}
for(j=0 ; j<i ; j++)						//for every row before the pivot row
{
mul = a[j][i] / a[i][i];				//multiplicator
for(k=0 ; k<u ; k++)					//Subtracting pivot row from each row before it
{
a[j][k] -= mul * a[i][k];
}
b[j] -= b[i]*mul;
}
printf("\nStep %d:\n",i+1);
for(j=0;j<e;j++)
{
for(k=0;k<u;k++)
printf("%5.2lf ",a[j][k]);
printf("| %5.2lf\n",b[j]);
}
}
for(i=0;i<e;i++)
{
b[i] /= a[i][i];
for(j=0;j<u;j++)
{
a[i][j] /= a[i][i];
}
}
printf("\nThe reduced row-echelon form:\n");
for(i=0;i<e;i++)								//Printing the reduced row-echelon form
{
for(j=0;j<u;j++)
{
printf("%5.2lf ",a[i][j]);
}
printf("| %5.2lf\n",b[i]);
}
/*e_eff = e;		eb = e;								//No of non-zero rows
for(i=0 ; i<e ; i++)							//To reduce no of equations if there is a zero row
{
for(j=0 ; a[i][j]==0 && j<u ; j++);
if(j==u)
{
if(b[i] == 0)
eb--;
e_eff--;
}
}
if(e_eff==eb && e_eff < u)
{
printf("Infinite solutions possible. Please enter valid data.\n");
goto label;
}
else if(e_eff!=eb && e_eff < u)
{
printf("No solution possible. Please enter valid data.\n");
goto label;
}
for(i=u-1,j=e_eff-1 ; i>=0 && j>=0 ; i--,j--)		//Back substituion
{
for(k=u-1 ; k>i ; k--)
{
b[j] -= a[j][k] * x[k];
}
x[i] = b[i] / a[i][i];
printf("x%d=%.3lf\n",i+1,x[i]);
}*/
for(i=0;i<u;i++)
{
printf("x%d=%.3lf\t",i+1,b[i]);
}
free(a);
free(b);
free(x);
return 0;
}
