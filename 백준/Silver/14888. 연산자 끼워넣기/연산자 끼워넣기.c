#include<stdio.h>
#include<malloc.h>

int *A=NULL, N, operation[4];

int find_max(int current,int value)
{
	int max=-1000000000, calculate;

	if(current==N-1)
	{
		if(operation[0])
			return value+A[current];
		else if(operation[1])
			return value-A[current];
		else if(operation[2])
			return value*A[current];
		else
			return value/A[current];
	}

	if(operation[0])
	{
		operation[0]--;
		calculate=find_max(current+1,value+A[current]);
		operation[0]++;
		max=calculate>max?calculate:max;
	}
	if(operation[1])
	{
		operation[1]--;
		calculate=find_max(current+1,value-A[current]);
		operation[1]++;
		max=calculate>max?calculate:max;
	}
	if(operation[2])
	{
		operation[2]--;
		calculate=find_max(current+1,value*A[current]);
		operation[2]++;
		max=calculate>max?calculate:max;
	}
	if(operation[3])
	{
		operation[3]--;
		calculate=find_max(current+1,value/A[current]);
		operation[3]++;
		max=calculate>max?calculate:max;
	}

	return max;
}

int find_min(int current,int value)
{
	int min=1000000000, calculate;

	if(current==N-1)
	{
		if(operation[0])
			return value+A[current];
		else if(operation[1])
			return value-A[current];
		else if(operation[2])
			return value*A[current];
		else
			return value/A[current];
	}

	if(operation[0])
	{
		operation[0]--;
		calculate=find_min(current+1,value+A[current]);
		operation[0]++;
		min=calculate<min?calculate:min;
	}
	if(operation[1])
	{
		operation[1]--;
		calculate=find_min(current+1,value-A[current]);
		operation[1]++;
		min=calculate<min?calculate:min;
	}
	if(operation[2])
	{
		operation[2]--;
		calculate=find_min(current+1,value*A[current]);
		operation[2]++;
		min=calculate<min?calculate:min;
	}
	if(operation[3])
	{
		operation[3]--;
		calculate=find_min(current+1,value/A[current]);
		operation[3]++;
		min=calculate<min?calculate:min;
	}

	return min;
}

int main(void)
{
	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);
	for(int i=0;i<4;i++)
		scanf("%d", &operation[i]);

	printf("%d\n%d\n", find_max(1,A[0]), find_min(1,A[0]));
	free(A);
	return 0;
}