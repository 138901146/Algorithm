#include<stdio.h>

int main(void)
{
	int info[2][2], endure[2];

	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			scanf("%d", &info[i][j]);

	for(int i=0;i<2;i++)
	{
		endure[i]=info[i][1]/info[(i+1)%2][0];
		endure[i]-=info[i][1]%info[(i+1)%2][0]==0;
	}

	if(endure[0]!=endure[1])
		printf("PLAYER %c\n", endure[0]>endure[1]?'A':'B');
	else
		printf("DRAW\n");
	return 0;
}