#include<stdio.h>
#include<stdlib.h>
void check(double *r_arr,double *r_new_arr,int n, int index)
{
	int count=0,i,temp=r_arr[index];
	double ans=r_arr[index];
	for(i=0;i<n;i++)
	{
		if(r_arr[i] == r_arr[index])
			count++;
	}
	if(count <= 1)
	{
		r_new_arr[index] = ans;
		return;
	}
	for(i=1;i<count;i++)
		ans += r_arr[index]-i;
	ans /= count;
	r_new_arr[index] = ans;
}
void main()
{

	int n,i,j,countx,county,flag=0,m;
	double *x,*y;
	double *ry,*rx,r,d2=0,AF=0,*new_rx,*new_ry;
	printf("Enter no. of records:");
	scanf("%d",&n);
	x = (double *) malloc(sizeof(double) * n);
	y = (double *) malloc(sizeof(double) * n);
	rx = (double *) malloc(sizeof(double) * n);
	new_rx = (double *) malloc(sizeof(double) * n);
	new_ry = (double *) malloc(sizeof(double) * n);
	ry = (double *) malloc(sizeof(double) * n);
	for(i=0;i<n;i++)
	{
		printf("For record %d:\n",i+1);
		printf("Enter x:");
		scanf("%lf",x+i);
		printf("Enter y:");
		scanf("%lf",y+i);
	}
	for(i=0;i<n;i++)
	{
		countx = 0;
		county = 0;
		for(j=0;j<n;j++)
		{
			if(j == i)
				continue;
			if(x[j] >= x[i])
				countx++;
			if(y[j] >= y[i])
				county++;
		}
		rx[i] = countx + 1;
		ry[i] = county + 1;
	}
	for(i=0;i<n;i++)
	{
		check(rx,new_rx,n,i);
		check(ry,new_ry,n,i);
	}
	for(i=0;i<n;i++)
	{
		m = 0;
		for(j=0;j<i;j++)
		{
			if(new_rx[i] == new_rx[j])
				flag = 1;
		}
		if(flag == 1)
		{
			flag = 0;
			continue;
		}
		for(j=i;j<n;j++)
		{
			if(new_rx[i] == new_rx[j])
				m++;
		}
		AF += (double) m*(m*m-1)/12;
	}
	for(i=0;i<n;i++)
	{
		m = 0;
		for(j=0;j<i;j++)
		{
			if(new_ry[i] == new_ry[j])
				flag = 1;
		}
		if(flag == 1)
		{
			flag = 0;
			continue;
		}
		for(j=i;j<n;j++)
		{
			if(new_ry[i] == new_ry[j])
				m++;
		}
		AF += (double) m*(m*m-1)/12;
	}
	printf("   x   |   y   |   Rx  |   Ry  |   D   |  D^2\n");
	for(i=0;i<n;i++)
	{
		d2 += (new_rx[i]-new_ry[i])*(new_rx[i]-new_ry[i]);
		printf("%7.2lf|%7.2lf|%7.2lf|%7.2lf|%7.2lf|%7.2lf\n",x[i],y[i],new_rx[i],new_ry[i],new_rx[i]-new_ry[i],(new_rx[i]-new_ry[i])*(new_rx[i]-new_ry[i]));
	}
	printf("Sum:\t\t\t\t\t%7.2lf\n",d2);
	r = 1 - (((6*d2)+AF)/(n*(n*n-1)));
	printf("\nAF=%.2lf\n",AF);
	printf("The Rank Corelation coefficient is:%lf",r);
	free(x);
	free(y);
	free(rx);
	free(ry);
	free(new_rx);
	free(new_ry);
}
