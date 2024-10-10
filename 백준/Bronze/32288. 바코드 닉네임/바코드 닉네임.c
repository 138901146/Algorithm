#include<stdio.h>

int main(void)
{
	int n;
	char S[501]={0};

	scanf("%d", &n);
	scanf("%s", S);

	for(int i=0;i<n;++i)
		if(S[i]=='l')
			S[i]='L';
		else
			S[i]='i';

	printf("%s", S);
	return 0;
}