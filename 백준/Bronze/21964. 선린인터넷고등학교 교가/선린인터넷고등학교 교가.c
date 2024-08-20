#include<stdio.h>

int main(void)
{
	int N;
	char S[100001]={0};

	scanf("%d", &N);
	scanf("%s", S);

	for(int i=N-5;i<N;++i)
		printf("%c", S[i]);
	return 0;
}