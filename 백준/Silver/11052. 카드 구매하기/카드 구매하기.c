#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *P=NULL;

	scanf("%d", &N);
	P=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;n++)
	{
		scanf("%d", &P[n]);

		for(int i=1;i<=n/2;i++)
			P[n]=P[n]>P[i]+P[n-i]?P[n]:P[i]+P[n-i];
	}

 	printf("%d\n", P[N]);
 	free(P);
 	return 0;
}