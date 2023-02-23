#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[101]={'\0', };

	scanf("%s", word);

	printf("%d\n", (int)strlen(word));

	return 0;
}