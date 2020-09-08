#include <stdio.h>
void main()
{ int i,j,x,k=0,n,a[20],z=0,b[20];
float sum=0, t,mean,medn,mod;
printf(“\n Enter the no. of elements (Max 20)\n”);
scanf(“%d”,&n);
printf(“Enter the elements\n”);
for(i=0;i
{scan (“%d”,&a[i]);}
for(i=0;i
{sum=sum+a[i];}
printf(“Sum: %f”,sum);
mean=sum/n;
}
for(i=0;i
{ for (j=i+1;j
  { if (a[i]>a[j])
      { t=a[i];a[i]=a[j];a[j]=t; }
 }
}
if (n%2==0)
 medn=(a[n/2]+a[(n/2)-1])/2;
else
medn=a[n/2];
for(i=0;i

{ for ( j=0; j<i; j++ )
  { if (a[i]==a[j])
      b[i]++;
  }
}
for(i=0;i<n;i++)
{ if (b[i]>z)
   z=b[i];
}
printf(“Mean :%f \n Median : %f \n Mean : “, mean, medn);
for I i=0; i<n; i++)
 { if (b[i]==z)
    printf(“%d\t”, a[i]);
}
}
