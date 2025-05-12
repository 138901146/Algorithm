#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, Q, x, duck, land;
	bool *occupied=NULL;

	scanf("%d%d", &N, &Q);
	occupied=(bool *)calloc(N+1,sizeof(bool));

	while(Q--)
	{
		duck=0;

		scanf("%d", &x);
		land=x;

		while(x)
		{
			if(occupied[x])
				duck=x;
			x>>=1;
		}

		printf("%d\n", duck);
		if(!duck)
			occupied[land]=true;
	}

	free(occupied);
	return 0;
}