#include<stdio.h>

int winner[1001][2];

int game(int stone,int turn)
{
	int next=turn^1;

	if(stone==0)
		return winner[stone][turn]=turn;
	else if(winner[stone][turn]!=-1)
		return winner[stone][turn];
	else if(stone>3 && game(stone-4,next)==turn)
		return winner[stone][turn]=turn;
	else if(stone>2 && game(stone-3,next)==turn)
		return winner[stone][turn]=turn;
	else if(stone>0 && game(stone-1,next)==turn)
		return winner[stone][turn]=turn;
	else
		return winner[stone][turn]=next;
}

int main(void)
{
	int N;

	scanf("%d", &N);
	for(int n=0;n<=N;n++)
		winner[n][0]=winner[n][1]=-1;

	printf("%s\n", game(N,0)?"CY":"SK");

	return 0;
}