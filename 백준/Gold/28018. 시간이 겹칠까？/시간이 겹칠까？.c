#include<stdio.h>

int N, S, E, Q, seat[1000002]={0}, time;

int main(void)
{
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d%d", &S, &E);
		++seat[S];
		--seat[E+1];
	}

	for(int n=1;n<1000002;++n)
		seat[n]+=seat[n-1];

	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d", &time);
		printf("%d\n", seat[time]);
	}

	return 0;
}