#include<stdio.h>
#include<string.h>

int main(void)
{
	int count=10;
	char plate[51]={'\0', };

	scanf("%s", plate);

	for(int i=1;i<strlen(plate);i++)
		count+=plate[i]==plate[i-1]?5:10;

	printf("%d\n", count);

	return 0;
}