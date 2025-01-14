#include<stdio.h>

int main(void)
{
	int T, N, ans[11]={1,1,2,6,4,0,};

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", ans[N]);
	}

	return 0;
}