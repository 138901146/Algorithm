#include<stdio.h>
#include<string.h>

int main(void)
{
	char ah[2][1000]={'\0', };

	for(int i=0;i<2;i++)
		scanf("%s", ah[i]);

	printf("%s\n", strlen(ah[0])>=strlen(ah[1])?"go":"no");

	return 0;
}