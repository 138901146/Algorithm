#include<stdio.h>
#include<string.h>

int main(void)
{
	char number[10]={'\0', };
	int left=0, right=0;

	scanf("%s", number);

	for(int i=0;i<strlen(number)/2;i++)
	{
		left+=number[i];
		right+=number[strlen(number)-1-i];
	}

	printf("%s\n", left==right?"LUCKY":"READY");
	return 0;
}