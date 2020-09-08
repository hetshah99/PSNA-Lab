#include<stdio.h>
#include<stdlib.h>

int findTotalInt(int *arr, int no_class) {
	int i;
	int sum;
	sum = 0;
	for(i=0;i<no_class;i++) {
		sum = sum + arr[i];
	}
	return sum;
}

float findTotalFloat(float *arr, int no_class)
{
	int i;
	float sum;
	sum = 0;
	for(i=0;i<no_class;i++) {
		sum = sum + arr[i];
	}
	return sum;
}

float findMean(float *ll, int *f, int no_class, int l)
{
	float *xf = (float *) malloc(no_class*sizeof(float)), *x = (float *) malloc(no_class*sizeof(float)), fxSum;
	int i, freqSum;
	for(i=0; i<no_class; i++) {
		x[i] = (ll[i] + (ll[i] + l)) / 2;
	}
	for(i=0; i<no_class; i++) {
		xf[i] = x[i] * f[i];
	}

	printf("\n\tClass Interval\tMid value\tFrequency\t\tfx\t\t");
	printf("\n");
	for(i=0;i<no_class;i++) {
		printf("\n\t%0.2f-%0.2f\t\t%0.2f\t\t%d\t\t%0.2f\t\t",ll[i],(ll[i]+l),x[i],f[i],xf[i]);
	}
	printf("\n");
	freqSum = findTotalInt(f,no_class);
	fxSum = findTotalFloat(xf,no_class);
	printf("\n\t\tTotal\t\t\t\t%d\t\t%.2f\t\t",freqSum,fxSum);
	printf("\n");
	free(xf);
	free(x);
	return (fxSum/freqSum);
}

float findMedian(float *ll, int *f, int no_class, int l) {
	int *cummu_freq = (int*) malloc(sizeof(int) * no_class);
	int m, N, i, sum = 0;
	float low;
	for(i=0;i<no_class;i++)
	{
		sum = sum + f[i];
		cummu_freq[i] = sum;
	}
	N = cummu_freq[i-1];

	printf("\n\tClass Interval\tFrequency\tCummulative Frequency\t");
	printf("\n");
	for(i=0;i<no_class;i++)
	{
		printf("\n\t%0.2f-%0.2f\t\t%d\t\t%d\t\t",ll[i],(ll[i]+l),f[i],cummu_freq[i]);
	}
	printf("\n");
	printf("\n\t\t\t\tN = %d\t\t\t\t",N);

	for(i=0;i<no_class;i++)
	{
		if(cummu_freq[i] > N/2)
			break;
	}
	low = ll[i];
	if(i!=0)
		m = cummu_freq[i-1];
	else
		m = 0;
	free(cummu_freq);
	return (low + (((((float)N/2) - m)/f[i])*l));
}

float findMode(float *ll, int *f, int no_class, int l) {
	int i, modal_class, freqPrev, freqNext;
	modal_class = 0;
	freqPrev = 0;
	for(i=0;i<no_class;i++)
	{
		if(f[i] > f[modal_class])
		{
			modal_class = i;
		}
	}
	if(modal_class != 0)
	{
		freqPrev = f[modal_class-1];
	}
	if(modal_class == (i-1))
	{
		freqNext = 0;
	}
	else
	{
		freqNext = f[modal_class + 1];
	}
	return (ll[modal_class] + (((float)(f[modal_class] - freqPrev) /  ((2*f[modal_class]) - freqPrev - freqNext)) * l));
}

int main()
{
	int ch, no_class, l, i,*f; float *ll;
	printf("Enter the number of classes you want to insert: ");
	scanf("%d", &no_class);
	printf("Enter the length of each class: ");
	scanf("%d", &l);
	ll = (float *) malloc(sizeof(float) * no_class);
	f = (int *) malloc(sizeof(int) * no_class);
	for(i=0;i<no_class;i++) {
		printf("\nEnter Lower Limit of Class %d: ",i+1);
		scanf("%f",&ll[i]);
		printf("Enter frequency of class %d: ",i+1);
		scanf("%d",&f[i]);
	}
	do {
		printf("\n\n----CHOICES----");
		printf("\n1. Mean");
		printf("\n2. Median");
		printf("\n3. Mode");
		printf("\n4. Exit");
		printf("\nEnter your choice(1-4): ");
		scanf("%d",&ch);
		switch(ch) {
			case 1: printf("\nThe Mean of the given data is %.2f", findMean(ll,f,no_class,l));
				break;
			case 2: printf("\nThe Median is %.2f", findMedian(ll,f,no_class,l));
				break;
			case 3: printf("\nThe Mode is %.2f", findMode(ll,f,no_class,l));
				break;
			case 4: exit(0);
				break;
			default: printf("Please Enter Valid Choice.");
				break;
		}
	} while(1);
	free(ll);
	free(f);
	return 0;
}
