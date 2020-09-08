//Newton-Raphson's method
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int d,iter=0,i,acc;
float x,fx=0,f1x=0,f2x=0,*p,temp,a,b,fa=0,fb=0;
printf("Enter degree of the equation:");
scanf("%d",&d);                                         //Scanning degree of equation
p=(float *)malloc((d+1)*sizeof(float));                 //Declaring array of co-efficients
printf("Enter coefficients:\n");
for(i=0;i<=d;i++)
{
printf("A%d for x^%d:",i,i);
scanf("%f",p+i);                                    //Scanning co-efficients
}
printf("\n Enter degree of accuracy:");                 //Scanning degree of accuracy
scanf("%d",&acc);
label1:
printf("Enter a:");
scanf("%f",&a);                                          //Scanning 'a'
label2:
printf("Enter b:");
scanf("%f",&b);                                             //Scanning 'b'
for(i=0;i<=d;i++)
{
fa += *(p+i)*pow(a,i);                              //Finding f(a)
fb += *(p+i)*pow(b,i);                              //Finding f(b)
}
if(fa>0 && fb>0)                                        //Checking if f(a)>0
{
printf("f(a) should be less than zero.");
fa=0;
fb=0;
goto label1;                                        //Returning control back to scanning a & b;
}
else if(fa<0 && fb<0)                                   //Checking if f(b)<0
{
printf("f(b) should be greater than zero.");
fb=0;
fa=0;
goto label2;                                        //Returning control back to scanning a & b;
}
printf("Enter the initial approximation between %f and %f:",a,b);
label:
scanf("%f",&x);                                         //Scanning x0
for(i=0;i<=d;i++)
{
fx += *(p+i)*pow(x,i);                              //Calculating f(x)
f1x += *(p+i)*(i)*pow(x,i-1);                       //Calculating f'(x)
f2x += *(p+i)*(i-1)*i*pow(x,i-2);                   //Calculating f''(x)
}
if(fabs(fx*f2x)>pow(f1x,2))                             //Checking the condition for convergence
{
printf("The initial approximation is incorrect. Enter a proper value:");
goto label;
}
printf("Sr.No. x(i)\tf(x)\tf'(x)\tx(i+1)\n");
do
{
iter++;
temp=x;                                            //Storing the value of x(i) in temp3
x=x-(fx/f1x);                                       //Calculating value of x(i+1)
printf("%d\t%.6f %.6f %.6f %.6f\n",iter,temp,fx,f1x,x);             //Printing the iteration
if(fabs(fx)<=pow(10,-acc))
{
printf("%.3f is the root of the equation.",x);  //Printing the root
break;                                              //Terminating the loop
}
fx=0; f1x=0;
for(i=0;i<=d;i++)
{
fx += *(p+i)*pow(x,i);                      //Calculating f(x)
f1x += *(p+i)*(i)*pow(x,i-1);               //Calculating f'(x)
}
}while(1);
free(p);
}
