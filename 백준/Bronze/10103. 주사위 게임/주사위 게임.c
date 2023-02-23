#include<stdio.h>

int main(void)
{
	int n, CY, SD, score_C=100, score_S=100;

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &CY, &SD);

		if(CY<SD)
			score_C-=SD;
		else if(CY>SD)
			score_S-=CY;
	}

	printf("%d\n%d\n", score_C, score_S);
	return 0;
}