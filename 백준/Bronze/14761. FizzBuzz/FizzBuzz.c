#include<stdio.h>

int main(void)
{
	int X, Y, N;

	scanf("%d %d %d", &X, &Y, &N);

	for(int n=1;n<=N;n++)
		if(n%X==0 && n%Y==0)
			printf("FizzBuzz\n");
		else if(n%X==0)
			printf("Fizz\n");
		else if(n%Y==0)
			printf("Buzz\n");
		else
			printf("%d\n", n);

	return 0;
}