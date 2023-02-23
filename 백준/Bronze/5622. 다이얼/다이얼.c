#include<stdio.h>
#include<string.h>

int main(void)
{
	int count=0;
	char str[16]={'\0', };

	scanf("%s", str);

	for(int i=0;i<strlen(str);i++)
		count+=3+(str[i]-'A'-(str[i]>='S')-(str[i]=='Z'))/3;
	printf("%d\n", count);

	return 0;
}