#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		char K[62]={'\0', };

		scanf("%s", K);
		printf("%s\n", K[strlen(K)-1]%2==0?"even":"odd");
	}

	return 0;
}