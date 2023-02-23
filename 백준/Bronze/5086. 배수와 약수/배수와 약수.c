#include<stdio.h>

int main(void)
{
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	while(num1!=0 || num2!=0)
	{
		printf("%s\n", num1<num2&&num2%num1==0?"factor":num1>num2&&num1%num2==0?"multiple":"neither");

		scanf("%d %d", &num1, &num2);
	}

	return 0;
}