#include<stdio.h>
#include<string.h>

int main(void)
{
	int alphabet[26]={0, };
	char S[101]={'\0', };

	scanf("%s", S);

	for(int i=0;i<strlen(S);i++)
		alphabet[S[i]-'a']++;

	for(int i=0;i<26;i++)
		printf("%d ", alphabet[i]);
	printf("\n");

	return 0;
}