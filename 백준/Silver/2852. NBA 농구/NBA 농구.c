#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int team, second;
}
status;

int compare(const void *x,const void *y)
{
	return ((status *)x)->second<((status *)y)->second?-1:1;
}

int main(void)
{
	int N, m, s, winning[2]={0}, score[2]={0};
	status goal[100];

	scanf("%d", &N);

	for(int n=0;n<N;++n)
	{
		scanf("%d%02d:%02d", &goal[n].team, &m, &s);
		goal[n].second=60*m+s;
	}

	qsort((void *)goal,(size_t)N,sizeof(status),compare);

	++score[goal[0].team-1];
	for(int n=1;n<N;++n)
	{
		if(score[0]<score[1])
			winning[1]+=goal[n].second-goal[n-1].second;
		else if(score[1]<score[0])
			winning[0]+=goal[n].second-goal[n-1].second;
		++score[goal[n].team-1];
	}

	if(score[0]<score[1])
		winning[1]+=2880-goal[N-1].second;
	else if(score[1]<score[0])
		winning[0]+=2880-goal[N-1].second;

	printf("%02d:%02d\n%02d:%02d", winning[0]/60, winning[0]%60, winning[1]/60, winning[1]%60);
	return 0;
}