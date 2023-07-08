#include<stdio.h>

int main(void)
{
	int length=0, count[26]={0, }, one=0;
	char str[51]={'\0', };

	scanf("%s", str);

	while(str[length]!='\0')
	{
		count[str[length]-'A']++;
		length++;
	}

	for(int i=0;i<26;i++)
		one+=count[i]&1;

	if(one>1)
		printf("I'm Sorry Hansoo\n");
	else
	{
		for(int i=0;i<26;i++)
			for(int j=0;j<(count[i]>>1);j++)
				printf("%c", i+'A');
		if(one)
			for(int i=0;i<26;i++)
				if(count[i]&1)
				{
					printf("%c", i+'A');
					break;
				}
		for(int i=25;i>=0;i--)
			for(int j=0;j<(count[i]>>1);j++)
				printf("%c", i+'A');
		printf("\n");
	}

	return 0;
}