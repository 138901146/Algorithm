#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char str[1000001];
	int count=0;

	fgets(str,sizeof(str),stdin);

	for(int i=0;i<strlen(str);i++)
		if(i==0&&isalpha(str[i]))
			count++;
		else if(i==0)
			continue;
		else if(!isalpha(str[i-1])&&isalpha(str[i]))
			count++;

	printf("%d\n", count);
	return 0;
}