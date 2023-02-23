#include<stdio.h>

int main(void)
{
	int result=0, number;
	char operator='\0';

	while(operator!='=')
	{
		scanf("%d", &number);

		switch(operator)
		{
			case '-':
						result-=number;
						break;
			case '*':
						result*=number;
						break;
			case '/':
						result/=number;
						break;
			default:
						result+=number;
						break;
		}

		getchar();
		scanf("%c", &operator);
	}

	printf("%d\n", result);
	return 0;
}