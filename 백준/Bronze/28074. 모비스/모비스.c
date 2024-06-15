#include<stdio.h>

int main(void)
{
	int current=0, flag=0;
	char str[101]={0};

	scanf("%s", str);

	while(str[current])
		switch(str[current++])
		{
			case 'M':
				flag|=1;
				break;
			case 'O':
				flag|=2;
				break;
			case 'B':
				flag|=4;
				break;
			case 'I':
				flag|=8;
				break;
			case 'S':
				flag|=16;
				break;
			default:
				break;
		}

	printf("%s", flag==31?"YES":"NO");
	return 0;
}