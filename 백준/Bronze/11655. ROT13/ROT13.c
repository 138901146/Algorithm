#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char S[101]={'\0', };

	fgets(S,sizeof(S),stdin);

	for(int i=0;i<strlen(S);i++)
		if(isalpha(S[i]))
			S[i]+=isupper(S[i])&&S[i]<'N' || islower(S[i])&&S[i]<'n'?13:-13;

	printf("%s", S);

	return 0;
}