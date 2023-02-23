#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[100001]={'\0', };
	int stack_count=0, count=0;

	scanf("%s", str);

	for(int i=0;i<strlen(str);i++)
		if(str[i]=='(')
			stack_count++;
		else
		{
			stack_count--;
			count+=str[i-1]=='('?stack_count:1;
		}

	printf("%d\n", count);
	return 0;
}