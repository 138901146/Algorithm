#include<stdio.h>
#include<stdlib.h>

int max(int *A,int plus,int minus,int multiply,int divide,int index,int N,int current)
{
	int max_num=-2000000000;

	if(index==N-1)
	{
		if(plus>0)
			return current+A[index];
		else if(minus>0)
			return current-A[index];
		else if(multiply>0)
			return current*A[index];
		else
			return current/A[index];
	}

	if(plus>0)
	{
		int cal=max(A,plus-1,minus,multiply,divide,index+1,N,current+A[index]);
		max_num=cal>max_num?cal:max_num;
	}
	if(minus>0)
	{
		int cal=max(A,plus,minus-1,multiply,divide,index+1,N,current-A[index]);
		max_num=cal>max_num?cal:max_num;
	}
	if(multiply>0)
	{
		int cal=max(A,plus,minus,multiply-1,divide,index+1,N,current*A[index]);
		max_num=cal>max_num?cal:max_num;
	}
	if(divide>0)
	{
		int cal=max(A,plus,minus,multiply,divide-1,index+1,N,current/A[index]);
		max_num=cal>max_num?cal:max_num;
	}

	return max_num;
}

int min(int *A,int plus,int minus,int multiply,int divide,int index,int N,int current)
{
	int min_num=2000000000;

	if(index==N-1)
	{
		if(plus>0)
			return current+A[index];
		else if(minus>0)
			return current-A[index];
		else if(multiply>0)
			return current*A[index];
		else
			return current/A[index];
	}

	if(plus>0)
	{
		int cal=min(A,plus-1,minus,multiply,divide,index+1,N,current+A[index]);
		min_num=cal<min_num?cal:min_num;
	}
	if(minus>0)
	{
		int cal=min(A,plus,minus-1,multiply,divide,index+1,N,current-A[index]);
		min_num=cal<min_num?cal:min_num;
	}
	if(multiply>0)
	{
		int cal=min(A,plus,minus,multiply-1,divide,index+1,N,current*A[index]);
		min_num=cal<min_num?cal:min_num;
	}
	if(divide>0)
	{
		int cal=min(A,plus,minus,multiply,divide-1,index+1,N,current/A[index]);
		min_num=cal<min_num?cal:min_num;
	}

	return min_num;
}

int main(void)
{
	int N, *A=NULL, plus, minus, multiply, divide;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	scanf("%d%d%d%d", &plus, &minus, &multiply, &divide);

	printf("%d\n%d\n", max(A,plus,minus,multiply,divide,1,N,A[0]), min(A,plus,minus,multiply,divide,1,N,A[0]));
	free(A);
	return 0;
}