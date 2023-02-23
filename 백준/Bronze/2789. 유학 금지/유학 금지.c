#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[101]={'\0', };

	scanf("%s", word);

	for(int i=0;i<strlen(word);i++)
		switch(word[i])
		{
			case 'C':
			case 'A':
			case 'M':
			case 'B':
			case 'R':
			case 'I':
			case 'D':
			case 'G':
			case 'E':
						break;
			default:
						printf("%c", word[i]);
						break;
		}
	printf("\n");

	return 0;
}