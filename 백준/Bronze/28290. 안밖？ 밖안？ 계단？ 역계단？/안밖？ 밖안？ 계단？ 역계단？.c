#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[9]={0};

	scanf("%s", str);

	if(!strcmp(str,"fdsajkl;") || !strcmp(str,"jkl;fdsa"))
		printf("in-out");
	else if(!strcmp(str,"asdf;lkj") || !strcmp(str,";lkjasdf"))
		printf("out-in");
	else if(!strcmp(str,"asdfjkl;"))
		printf("stairs");
	else if(!strcmp(str,";lkjfdsa"))
		printf("reverse");
	else
		printf("molu");
	return 0;
}