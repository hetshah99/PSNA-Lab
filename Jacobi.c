//Gauss-Jacobi
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
  int u,i,j,flag=1,count,acc,max,k;
  double **a,*b,*x,*xd,lhs,temp,lhs2;
  printf("Enter the number of unknowns:");
  scanf("%d",&u);
  a = (double **) malloc(sizeof(double) * u);					//Coefficients of Equations
  b = (double *) malloc(sizeof(double) * u);					//Constants of the equation
  x = (double *) malloc(sizeof(double) * u);					//Unknowns
  xd = (double *) malloc(sizeof(double) * u);					//Unknowns (duplicate)
  for(i=0;i<u;i++)
      *(a+i) = (double *) malloc(sizeof(double)*u);
  printf("Enter the data:\n");
  for(i=0;i<u;i++)
      {
          for(j=0;j<u;j++)
          {
            printf("a%d%d:",i+1,j+1);
              scanf("%lf",&a[i][j]);								//Scanning Coefficients
          }
    printf("b%d:",i+1);
    scanf("%lf",&b[i]);										//Scanning constants
      }
    for(i=0;i<u;i++)											//Checking row-by-row
      {
        lhs = 0;												//'lhs' is sum of coefficients of the row excluding pivot element's coefficient
        max = i;												//max is the row index of the pivot column
          for(j=0;j<u;j++)										//Calculating lhs of the row
            {
              if(j==i)
              continue;
              lhs += fabs(a[i][j]);
            }
          if(lhs > fabs(a[i][i]))									//If the sum of coefficients is more than the pivot element coefficient
            {
              for(j=0;j<u;j++)									//Checking for the row with such property
              {
                if(j==i)
                continue;
                lhs2 = 0;										//'lhs2' is the sum of coefficients of the rows excluding the pivot column element
                for(k=0;k<u;k++)								//Calculating lhs2
                  {
                    if(k==i)
                    continue;
                    lhs2 += fabs(a[j][k]);
                  }
                    if(lhs2 < fabs(a[j][i]))						//Checking if the row possess the property
                    {
                      max = j;									//If so, store its row index in max
                      break;
                    }
                  }
                }
        if(max != i)											//If max row and i row are different
                {
                  for(j=0;j<u;j++)									//Swap the (i)th row with (max)th row
                  {
                    temp = a[max][j];
                    a[max][j] = a[i][j];
                    a[i][j] = temp;
                  }
                  temp = b[max];
                  b[max] = b[i];
                  b[i] = temp;
                }
              }
  printf("\nThe matrix Formed:\n");										//Printing the matrix formed at last
    for(i=0;i<u;i++)
    {
      for(j=0;j<u;j++)
      {
        printf("%.6lf ",a[i][j]);
      }
      printf("| %.6lf\n",b[i]);
    }
    printf("Enter initial approximations:\n");								//Scanning initial approx.
    for(i=0;i<u;i++)
    {
      printf("x%d:",i);
      scanf("%lf",&x[i]);
    }
    printf("Enter degree of accuracy:");									//Scanning degree of accuracy
    scanf("%d",&acc);
    printf("\n");
    for(i=0;i<u;i++)
    {
      printf("    x%d   ",i);
    }
    printf("\n");
    while(flag)
      {
        for(i=0;i<u;i++)					//Assigning duplicacy
        {
          xd[i] = x[i];
        }

          for(i=0;i<u;i++)					//Calculating new Xi(s)
            {
              x[i] = b[i];
              for(j=0;j<u;j++)
              {
                if(i==j)
                continue;
                x[i] -= a[i][j]*xd[j];
              }
          x[i] /= a[i][i];
          printf("%.6lf ",x[i]);
        }
        printf("\n");

        count=0;
        for(i=0;i<u;i++)						//Checking for the end
        {
          if(fabs(x[i]-xd[i]) <= pow(10,-acc))
          count++;
        }

        if(count == u)
        flag = 0;
      }
      printf("\nThe answer is:\n");
      for(i=0;i<u;i++)
        {
          printf("x%d=%lf\n",i,x[i]);
          		//Printing the answer
        }
        free(x);
        free(a);
        free(b);
}
