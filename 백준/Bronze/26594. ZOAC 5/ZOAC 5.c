#include<stdio.h>

char str[1000001]={0};

int main(void)
{
	int count=0;

	scanf("%s", str);

	while(str[0]==str[++count]);

	printf("%d", count);
	return 0;
}