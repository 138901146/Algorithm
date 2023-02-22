#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	int N;

	scanf("%d", &N);
	while(N>0)
	{
		char str[6]={'\0', };
		bool isPalindrome=true;

		sprintf(str,"%d", N);

		for(int i=0;i<strlen(str)/2;i++)
			if(str[i]!=str[strlen(str)-1-i])
			{
				isPalindrome=false;
				break;
			}

		printf("%s\n", isPalindrome?"yes":"no");

		scanf("%d", &N);
	}

	return 0;
}