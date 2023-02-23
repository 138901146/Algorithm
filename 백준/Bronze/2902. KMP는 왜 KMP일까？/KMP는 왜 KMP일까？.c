#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	int count=0;
	char first[101]={'\0', }, second[101]={'\0', };

	scanf("%s", first);

	for(int i=0;i<strlen(first);i++)
		if(isupper(first[i]))
			second[count++]=first[i];

	printf("%s\n", second);

	return 0;
}