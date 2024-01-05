#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *Q=NULL, *P=NULL, primary=0, secondary;

	scanf("%d", &N);
	Q=(int *)malloc(N*sizeof(int));
	P=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &Q[i], &P[i]);

		if(Q[i]>Q[primary] || Q[i]==Q[primary]&&P[i]<P[primary])
			primary=i;
	}
	secondary=primary?0:1;
	for(int i=0;i<N;++i)
	{
		if(i==primary)
			continue;

		if(Q[i]>Q[secondary] || Q[i]==Q[secondary]&&P[i]<P[secondary])
			secondary=i;
	}
	printf("%d %d %d %d\n", Q[primary], P[primary], Q[secondary], P[secondary]);

	primary=0;
	for(int i=1;i<N;++i)
		if(P[i]<P[primary] || P[i]==P[primary]&&Q[i]>Q[primary])
			primary=i;
	secondary=primary?0:1;
	for(int i=0;i<N;++i)
	{
		if(i==primary)
			continue;

		if(P[i]<P[secondary] || P[i]==P[secondary]&&Q[i]>Q[secondary])
			secondary=i;
	}
	printf("%d %d %d %d", Q[primary], P[primary], Q[secondary], P[secondary]);

	free(P);
	free(Q);
	return 0;
}