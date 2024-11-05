#include<stdio.h>

int main(void)
{
	int N;

	for(int i=0;i<8;++i)
	{
		scanf("%d", &N);

		if(N==9)
		{
			printf("F");
			return 0;
		}
	}

	printf("S");
	return 0;
}