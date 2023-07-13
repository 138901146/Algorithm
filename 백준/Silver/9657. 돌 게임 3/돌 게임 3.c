#include<stdio.h>
#include<stdbool.h>

int game[1001];

bool stone(int N)
{
	if(N<0)
		return true;
	else if(N==0)
		return false;
	else if(game[N]!=-1)
		return game[N];
	game[N]=!(stone(N-1)&&stone(N-3)&&stone(N-4));

	return game[N];
}

int main(void)
{
	int N;

	scanf("%d", &N);
	for(int n=0;n<=N;n++)
		game[n]=-1;

	printf("%s\n", stone(N)?"SK":"CY");
	return 0;
}