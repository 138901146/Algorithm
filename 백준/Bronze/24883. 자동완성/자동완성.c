#include<stdio.h>

int main(void)
{
	char c;

	scanf("%c", &c);

	printf("%s\n", c=='n'||c=='N'?"Naver D2":"Naver Whale");
	return 0;
}