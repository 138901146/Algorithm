#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[1001]={'\0', };

	scanf("%s", word);

	for(int w=0;w<strlen(word);w++)
		word[w]=word[w]<'D'?word[w]+23:word[w]-3;

	printf("%s", word);
	return 0;
}