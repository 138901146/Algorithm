#include<stdio.h>

int main(void)
{
	int N, M;

	scanf("%d %d", &N, &M);

	if(M<3)
		printf("NEWBIE!\n");
	else if(M<=N)
		printf("OLDBIE!\n");
	else
		printf("TLE!\n");

	return 0;
}