#include<stdio.h>
#include<string.h>

int main(void)
{
	long int order=0;
	char str[11]={'\0', };

	scanf("%s", str);

	for(int i=0;i<strlen(str);i++)
	{
		order*=26;
		order+=str[i]-'A'+1;
	}

	printf("%ld\n", order);
	return 0;
}