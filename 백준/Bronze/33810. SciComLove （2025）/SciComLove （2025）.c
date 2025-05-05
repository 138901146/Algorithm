#include<stdio.h>

int main(void)
{
	int diff=0;
	char S[11]={0}, origin[11]={'S','c','i','C','o','m','L','o','v','e'};

	scanf("%s", S);

	for(int i=0;i<10;++i)
		diff+=S[i]!=origin[i];

	printf("%d", diff);
	return 0;
}