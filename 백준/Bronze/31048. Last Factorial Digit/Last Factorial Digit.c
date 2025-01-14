#include<stdio.h>

int main(void)
{
	int T, N;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		switch(N)
		{
			case 0:
				++N;
			case 1:
			case 2:
			case 4:
				printf("%d\n", N);
				break;
			case 3:
				printf("6\n");
				break;
			default:
				printf("0\n");
				break;
		}
	}

	return 0;
}