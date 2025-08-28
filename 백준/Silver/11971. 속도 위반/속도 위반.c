#include<stdio.h>

int main(void)
{
	int N, M, limit[100], n=0, m=0, max=0, length, speed;

	scanf("%d%d", &N, &M);
	while(N--)
	{
		scanf("%d%d", &length, &speed);
		for(int i=0;i<length;++i)
			limit[n+i]=speed;
		n+=length;
	}
	while(M--)
	{
		scanf("%d%d", &length, &speed);
		for(int i=0;i<length;++i)
			max=speed-limit[m+i]<max?max:speed-limit[m+i];
		m+=length;
	}

	printf("%d", max);
	return 0;
}