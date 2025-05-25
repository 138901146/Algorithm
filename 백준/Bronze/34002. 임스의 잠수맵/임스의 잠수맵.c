#include<stdio.h>

int main(void)
{
	int A, B, C, S, V, L, minute=0;

	scanf("%d%d%d", &A, &B, &C);
	scanf("%d%d", &S, &V);
	scanf("%d", &L);

	L*=100;
	while(L<25000)
	{
		if(V)
		{
			--V;
			for(int i=0;i<30&&L<25000;++i,++minute,L+=C);
		}
		else if(S)
		{
			--S;
			for(int i=0;i<30&&L<25000;++i,++minute,L+=B);
		}
		else
		{
			++minute;
			L+=A;
		}
	}

	printf("%d", minute);
	return 0;
}