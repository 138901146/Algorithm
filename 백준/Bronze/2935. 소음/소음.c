#include<stdio.h>
#include<string.h>

int main(void)
{
	char c, number[101]={'\0', };
	int A, B;

	scanf("%s", number);
	A=strlen(number);
	getchar();
	scanf("%c", &c);
	scanf("%s", number);
	B=strlen(number);

	if(c=='*')
	{
		printf("1");
		for(int i=0;i<A+B-2;i++)
			printf("0");
		printf("\n");
	}
	else
	{
		if(A==B)
		{
			printf("2");
			for(int i=0;i<A-1;i++)
				printf("0");
		}
		else
		{
			if(A<B)
			{
				int temp=A;
				A=B;
				B=temp;
			}

			printf("1");
			for(int i=0;i<A-1;i++)
				printf("%d", A-i-1==B?1:0);
		}
		printf("\n");
	}

	return 0;
}