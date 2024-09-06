#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);
	getchar();

	for(int i=1;i<=N;++i)
	{
		char str[52]={0};

		fgets(str,sizeof(str),stdin);
		printf("%d. %s", i, str);
	}

	return 0;
}