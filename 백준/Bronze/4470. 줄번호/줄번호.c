#include<stdio.h>

int main(void)
{
	int N;
	char str[52]={0};

	scanf("%d", &N);
	getchar();

	for(int i=1;i<=N;++i)
	{
		fgets(str,sizeof(str),stdin);
		printf("%d. %s", i, str);
	}

	return 0;
}