#include<stdio.h>

int main(void)
{
	int L, R, sum=0, pow=1;

	scanf("%d", &L);
	scanf("%d", &R);

	while(L>5)
	{
		if(pow!=1)
			sum+=pow*L;
		L*=R;
		L/=100;
		pow*=2;
	}

	printf("%d\n", sum);
	return 0;
}