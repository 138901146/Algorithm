#include<stdio.h>

int main(void)
{
	int N=0;
	char str[100][100]={'\0'};

	while(gets(str[N])!=NULL)
		puts(str[N++]);
 
	return 0;
}