#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char hex[7]={'\0', };
	int dec=0;

	scanf("%s", hex);

	for(int i=0;i<strlen(hex);i++)
	{
		dec*=16;
		dec+=isdigit(hex[i])?hex[i]-'0':hex[i]-'A'+10;
	}

	printf("%d\n", dec);
	return 0;
}