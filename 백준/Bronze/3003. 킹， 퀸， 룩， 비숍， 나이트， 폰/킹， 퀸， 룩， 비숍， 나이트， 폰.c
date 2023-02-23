#include<stdio.h>

int main(void)
{
	int chess[2][6]={{1,1,2,2,2,8},{0, }};

	for(int i=0;i<6;i++)
		scanf("%d", &chess[1][i]);

	for(int i=0;i<6;i++)
		printf("%d ", chess[0][i]-chess[1][i]);
	printf("\n");
	return 0;
}