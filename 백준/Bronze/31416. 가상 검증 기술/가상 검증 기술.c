#include<stdio.h>

int min(int x,int y)
{
	return x<y?x:y;
}

int max(int x,int y)
{
	return x<y?y:x;
}

int main(void)
{
	int Q;

	scanf("%d", &Q);

	while(Q--)
	{
		int Ta, Tb, Va, Vb, B, ans=20000;

		scanf("%d%d%d%d", &Ta, &Tb, &Va, &Vb);

		B=Tb*Vb;

		for(int a=0;a<=Va;++a)
			ans=min(ans,max(Ta*a,Ta*(Va-a)+B));

		printf("%d\n", ans);
	}

	return 0;
}