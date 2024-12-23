#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		int count=0;
		char str[101]={0};

		scanf("%s", str);

		for(int i=0;str[i];++i)
			++count;

		printf("%d\n", count);
	}

	return 0;
}