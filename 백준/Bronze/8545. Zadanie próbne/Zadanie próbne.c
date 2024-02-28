#include<stdio.h>

int main(void)
{
	char s[4]={'\0'};

	scanf("%s", s);

	for(int i=2;i>=0;--i)
		printf("%c", s[i]);
	return 0;
}