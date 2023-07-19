#include<stdio.h>
#include<stdbool.h>

int marble[501][501][2], b[3];

bool marble_game(int k1,int k2,int turn)
{
	if(k1<0 || k2<0)
		return turn;
	else if(k1==0 && k2==0)
		return !turn;
	else if(marble[k1][k2][turn]!=-1)
		return marble[k1][k2][turn];
	else if(marble[k1][k2][!turn]!=-1)
		return marble[k1][k2][turn]=!marble[k1][k2][!turn];
	for(int i=0;i<3;i++)
		if(marble_game(k1-b[i],k2,turn^1)==turn || marble_game(k1,k2-b[i],turn^1)==turn)
			return marble[k1][k2][turn]=turn;
	return marble[k1][k2][turn]=!turn;
}

int main(void)
{
	int k1, k2;

	for(int i=0;i<3;i++)
		scanf("%d", &b[i]);

	for(int t=0;t<5;t++)
	{
		scanf("%d%d", &k1, &k2);
		for(int i=0;i<=k1;i++)
			for(int j=0;j<=k2;j++)
				marble[i][j][0]=marble[i][j][1]=-1;
		printf("%c\n", marble_game(k1,k2,1)?'A':'B');
	}

	return 0;
}