#include<stdio.h>

int main(void)
{
	int N;
	char S[101];

	scanf("%d", &N);
	scanf("%s", S);

	for(int n=1;n<N;++n)
		if(S[n]!=S[n-1])
		{
			printf("No");
			return 0;
		}

	printf("Yes");
	return 0;
}