#include<stdio.h>

int main(void)
{
	char str[100][101]={'\0'};
	int N=0;

	while(gets(str[N])!='\0')
		puts(str[N++]);

	return 0;
}