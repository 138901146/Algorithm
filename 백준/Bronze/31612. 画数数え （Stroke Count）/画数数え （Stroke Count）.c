#include<stdio.h>

int main(void)
{
	int N, count=0;
	char S[101]={0};

	scanf("%d", &N);
	scanf("%s", S);

	while(N--)
		count+=S[N]=='o'?1:2;

	printf("%d", count);
	return 0;
}