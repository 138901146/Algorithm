#include<stdio.h>

int main(void)
{
	int length=1;
	char str[1001]={0};

	gets(str);

	while(str[++length]!='y');

	printf("h");
	while(--length)
		printf("ee");
	printf("y");

	return 0;
}