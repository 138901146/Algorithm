#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[101]={'\0', };
	int vowel=0;

	scanf("%s", word);

	for(int i=0;i<strlen(word);i++)
		vowel+=word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u';

	printf("%d\n", vowel);

	return 0;
}