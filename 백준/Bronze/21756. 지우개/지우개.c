#include<stdio.h>

int main(void)
{
	int N, ans=1;

	scanf("%d", &N);

	while(ans<=N)
		ans<<=1;

	printf("%d", ans>>1);
	return 0;
}