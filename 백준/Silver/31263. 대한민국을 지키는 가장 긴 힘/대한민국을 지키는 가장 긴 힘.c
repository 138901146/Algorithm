#include<stdio.h>

#define INF 9999

int main(void)
{
	int N, S[5000], min[5000];

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		scanf("%1d", &S[n]);

	min[0]=min[1]=1;
	min[2]=100*S[0]+10*S[1]+S[2]<642?1:2;
	for(int n=3;n<N;++n)
	{
		min[n]=INF;

		if(S[n-2] && 100*S[n-2]+10*S[n-1]+S[n]<642)
			min[n]=min[n-3]+1;
		if(S[n-1])
			min[n]=min[n-2]+1<min[n]?min[n-2]+1:min[n];
		if(S[n])
			min[n]=min[n-1]+1<min[n]?min[n-1]+1:min[n];
	}

	printf("%d", min[N-1]);
	return 0;
}