#include<stdio.h>
#include<stdlib.h>

double maximum_partial_array(double *arr,int size)
{
	double mul=1.0, max=arr[0];

	for(int i=0;i<size;i++)
	{
		mul=arr[i]*mul>arr[i]?arr[i]*mul:arr[i];
		max=max>mul?max:mul;
	}

	return max;
}

int main(void)
{
	int N;
	double *arr=NULL;

	scanf("%d", &N);
	arr=(double *)malloc(N*sizeof(double));

	for(int n=0;n<N;n++)
		scanf("%lf", &arr[n]);

	printf("%.3lf\n", maximum_partial_array(arr,N));
	free(arr);
	return 0;
}