//Langrange Interpolation
#include<stdio.h>
#include<stdlib.h>
double calcX(double xi, double *x, int i, int n)			//Calculating (x-x0)(x-x1)(x-x2)...(x-xn)
{
double ans=1; int j;
for(j=0;j<n;j++)
{
if(j==i)
continue;
ans *= (xi - x[j]);
}
return ans;
}
int main()
{
int n,i;												//'n' for no. of data, 'i' as index

double *x, *y, xp, yp=0;
printf("Enter no. of datas:");
scanf("%d",&n);											//Scanning no. of data
x = (double *)malloc(n*sizeof(double));
y = (double *)malloc(n*sizeof(double));
label1:
printf("\nEnter data:\n");
for(i=0;i<n;i++)
{
printf("x%d and f(x%d):",i,i);
scanf("%lf%lf",x+i,y+i);							//Scanning data
}
printf("Enter xp:");
scanf("%lf",&xp);										//Scanning x(p)
for(i=0;i<n;i++)
{
yp += calcX(xp,x,i,n)/calcX(x[i],x,i,n)*y[i];		//Calculating f(x(p))
}
printf("f(%.6lf)=%.8f",xp,yp);							//Printing the result
free(x);
free(y);
return 0;
}
