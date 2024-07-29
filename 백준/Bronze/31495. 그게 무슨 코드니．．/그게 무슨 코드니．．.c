#include<stdio.h>
#include<string.h>

int main(void)
{
	int length;
	char S[51]={0};

	gets(S,sizeof(S),stdin);

	length=strlen(S)-1;

	if(length<=1 || S[0]!='\"' || S[length]!='\"')
	{
		printf("CE");
		return 0;
	}

	for(int i=1;i<length;++i)
		printf("%c", S[i]);
	return 0;
}