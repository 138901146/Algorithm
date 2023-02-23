#include<stdio.h>
#include<string.h>

int main(void)
{
	int alphabet[26];
	char S[101]={'\0', };

	fgets(S,sizeof(S),stdin);
	for(int i=0;i<26;i++)
		alphabet[i]=-1;

	for(int i=0;i<strlen(S);i++)
		alphabet[S[i]-'a']=alphabet[S[i]-'a']==-1?i:alphabet[S[i]-'a'];

	for(int i=0;i<26;i++)
		printf("%d ", alphabet[i]);

	return 0;
}