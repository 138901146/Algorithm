#include<stdio.h>

int main(void)
{
	int continuous=0;
	char str[31]={0};

	scanf("%s", str);

	for(int i=0;str[i];++i)
		if(str[i]=='s')
		{
			if(++continuous==2)
			{
				printf("hiss");
				return 0;
			}
		}
		else
			continuous=0;

	printf("no hiss");
	return 0;
}