#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	for(int x=1;x<11;++x)
	{
		int found=0;

		for(int y=1;y<11;++y)
			if(A*x+B*y==C)
			{
				found=1;
				printf("%d ", y);
			}

		if(!found)
			printf("0");
		printf("\n");
	}

	return 0;
}