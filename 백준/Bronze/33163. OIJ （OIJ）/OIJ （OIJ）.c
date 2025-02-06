#include<stdio.h>

int main(void)
{
	int N;
	char S[101]={0};

	scanf("%d", &N);
	scanf("%s", S);

	for(int n=0;n<N;++n)
		S[n]=S[n]=='J'?'O':S[n]=='O'?'I':'J';

	printf("%s", S);
	return 0;
}