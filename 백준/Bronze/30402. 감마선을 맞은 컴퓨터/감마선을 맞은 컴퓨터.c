#include<stdio.h>

int main(void)
{
	char c;

	for(int i=0;i<15;++i)
		for(int j=0;j<15;++j)
		{
			scanf("%c", &c);
			getchar();

			if(c=='w')
			{
				printf("chunbae");
				return 0;
			}
			else if(c=='b')
			{
				printf("nabi");
				return 0;
			}
			else if(c=='g')
			{
				printf("yeongcheol");
				return 0;
			}
		}

	return 0;
}