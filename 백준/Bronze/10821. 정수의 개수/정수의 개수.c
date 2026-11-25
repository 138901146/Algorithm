#include<stdio.h>
#include<string.h>

int main(void)
{
	int count=0;
	char S[101]={0};

	scanf("%s", S);

	for(int i=0;i<strlen(S);++i)
		if(S[i]==',')
			++count;

	printf("%d", count+1);
	return 0;
}