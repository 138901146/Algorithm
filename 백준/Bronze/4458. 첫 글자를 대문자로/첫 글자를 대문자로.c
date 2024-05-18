#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	getchar();
	while(N--)
	{
		char str[50]={0};

		fgets(str,sizeof(str),stdin);

		if(96<str[0])
			str[0]-=32;

		printf("%s", str);
	}

	return 0;
}