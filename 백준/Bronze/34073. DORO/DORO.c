#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		char word[101]={0};

		scanf("%s", word);
		printf("%sDORO ", word);
	}

	return 0;
}