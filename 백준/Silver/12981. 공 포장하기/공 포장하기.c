#include<stdio.h>

int main(void)
{
	int R, G, B, total;

	scanf("%d%d%d", &R, &G, &B);

	total=R/3+G/3+B/3;
	R%=3;
	G%=3;
	B%=3;

	while(R&&G&&B)
	{
		--R;
		--G;
		--B;
		++total;
	}

	if(R&&G)
		total+=R==1&&G==1?1:2;
	else if(R&&B)
		total+=R==1&&B==1?1:2;
	else if(G&&B)
		total+=G==1&&B==1?1:2;
	else if(R||G||B)
		++total;

	printf("%d", total);
	return 0;
}