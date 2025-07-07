#include<stdio.h>

int main(void)
{
	int N, x;

	scanf("%d", &N);

	while(N)
	{
		int previous=0;

		while(N--)
		{
			scanf("%d", &x);

			if(x!=previous)
				printf("%d ", x);
			previous=x;
		}

		printf("$\n");
		scanf("%d", &N);
	}

	return 0;
}