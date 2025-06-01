#include<stdio.h>

#define INF 9999999

int main(void)
{
	int N, A[2], result[2][4]={-INF,-INF,-INF,-INF}, previous=1, current=0;

	scanf("%d", &N);

	while(N--)
	{
		current^=1;
		previous^=1;

		for(int i=0;i<4;++i)
			result[current][i]=result[previous][i];

		scanf("%d", &A[current]);

		result[current][0]=result[current][0]<-A[current]?-A[current]:result[current][0];
		result[current][1]=result[current][1]<result[previous][0]+A[current]?result[previous][0]+A[current]:result[current][1];
		result[current][2]=result[current][2]<result[previous][1]-A[current]?result[previous][1]-A[current]:result[current][2];
		result[current][3]=result[current][3]<result[previous][2]+A[current]?result[previous][2]+A[current]:result[current][3];
	}

	printf("%d", result[current][3]);
	return 0;
}