#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *T=NULL, *P=NULL, *counsel=NULL, max=0;

	scanf("%d", &N);
	T=(int *)malloc(N*sizeof(int));
	P=(int *)malloc(N*sizeof(int));
	counsel=(int *)calloc(N+1,sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d%d", &T[i], &P[i]);

	for(int i=N-1;i>=0;i--)
		if(i+T[i]<=N)
		{
			counsel[i]=counsel[i+1]<P[i]+counsel[i+T[i]]?P[i]+counsel[i+T[i]]:P[i];
			if(counsel[i]>max)
				max=counsel[i];
			else
				counsel[i]=max;
		}
		else
			counsel[i]=counsel[i+1];

	printf("%d\n", max);
	free(counsel);
	free(P);
	free(T);
	return 0;
}