#include<stdio.h>

int main(void)
{
	int N, score[12][2]={{0,0},{12,1600},{11,894},{11,1327},{10,1311},{9,1004},{9,1178},{9,1357},{8,837},{7,1055},{6,556},{6,773}};

	scanf("%d", &N);

	printf("%d %d", score[N][0], score[N][1]);
	return 0;
}