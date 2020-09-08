#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	/*
	int n=5,i;
	double x[]={6,2,10,4,8}, y[]={9,11,5,8,7};
	*/
	int n,i; double *x,*y;
	double x1=0,y1=0,x2=0,y2=0,xy=0,r;
	printf("Enter the no. of data:");
	scanf("%d",&n);
	x = (double *) malloc(sizeof(double) * n);
	y = (double *) malloc(sizeof(double) * n);
	printf("Enter the data:\n");
	for(i=0;i<n;i++)
	{
		printf("For record %d:\n",i+1);
		printf("Enter x:");
		scanf("%lf",x+i);

		printf("Enter y:");
		scanf("%lf",y+i);
	}
	printf("\n         x          y         x^2        y^2         xy\n");
	for(i=0;i<n;i++)
	{
		x1 += x[i];
		y1 += y[i];
		x2 += x[i]*x[i];
		y2 += y[i]*y[i];
		xy += x[i]*y[i];
		printf("    %10lf %10lf %10lf %10lf %10lf\n",x[i],y[i],x[i]*x[i],y[i]*y[i],x[i]*y[i]);
	}
	printf("Sum:%10lf %10lf %10lf %10lf %10lf\n",x1,y1,x2,y2,xy);
	r = ((n*xy) -(x1*y1)) / (sqrt((n*x2-x1*x1) * (n*y2-y1*y1)));
	printf("\nThe Pearson's co-relation co-efficient:%lf",r);
	free(x);
	free(y);
}
