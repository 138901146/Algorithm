#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	char word[101]={'\0', };
	bool isPalindrome=true;

	scanf("%s", word);

	for(int i=0;i<strlen(word)/2;i++)
		if(word[i]!=word[strlen(word)-1-i])
		{
			isPalindrome=false;
			break;
		}

	printf("%d\n", isPalindrome);

	return 0;
}