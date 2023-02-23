#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	int X=0;
	char number[15]={'\0', };

	scanf("%s", number);

	if(strncmp(number,"0x",2)==0)
		for(int i=2;i<strlen(number);i++)
		{
			X*=16;
			X+=isdigit(number[i])?number[i]-'0':number[i]+10-'a';
		}
	else if(number[0]=='0')
		for(int i=1;i<strlen(number);i++)
		{
			X*=8;
			X+=number[i]-'0';
		}
	else
		X=atoi(number);

	printf("%d\n", X);
	return 0;
}