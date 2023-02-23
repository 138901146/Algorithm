#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N;
	bool solved=false;

	scanf("%d", &N);

	for(int sum=2;!solved;sum++)
		for(int b=1;!solved&&b<sum;b++,N--)
			if(N==1)
			{
				solved=true;
				printf("%d %d\n", sum-b, b);
			}

	return 0;
}