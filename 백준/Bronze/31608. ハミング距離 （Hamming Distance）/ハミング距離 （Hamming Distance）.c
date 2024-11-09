#include<stdio.h>

int main(void)
{
	int N, diff=0;
	char S[101]={0}, T[101]={0};

	scanf("%d", &N);
	scanf("%s", S);
	scanf("%s", T);

	while(N--)
		diff+=S[N]!=T[N];

	printf("%d", diff);
	return 0;
}