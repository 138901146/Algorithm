#include<stdio.h>

int main(void)
{
	int L, P, V;

	scanf("%d %d %d", &L, &P, &V);
	for(int i=1;L!=0||P!=0||V!=0;i++)
	{
		printf("Case %d: %d\n", i, V%P>=L?L*(V/P)+L:L*(V/P)+V%P);
		scanf("%d %d %d", &L, &P, &V);
	}

	return 0;
}