#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[1001]={'\0', };

	scanf("%s", str);

	for(int i=0;i<strlen(str);i++)
		str[i]=str[i]>='a'&&str[i]<='z'?str[i]-32:str[i]+32;

	printf("%s\n", str);
	return 0;
}