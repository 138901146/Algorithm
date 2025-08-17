#include<stdio.h>

int main(void)
{
	int N, m, s, team[100], sec[100], win[2]={0}, score[2]={0};

	scanf("%d", &N);

	for(int n=0;n<N;++n)
	{
		scanf("%d%02d:%02d", &team[n], &m, &s);
		sec[n]=60*m+s;
	}

	++score[team[0]-1];
	for(int n=1;n<N;++n)
	{
		if(score[0]<score[1])
			win[1]+=sec[n]-sec[n-1];
		else if(score[1]<score[0])
			win[0]+=sec[n]-sec[n-1];
		++score[team[n]-1];
	}

	if(score[0]<score[1])
		win[1]+=2880-sec[N-1];
	else if(score[1]<score[0])
		win[0]+=2880-sec[N-1];

	printf("%02d:%02d\n%02d:%02d", win[0]/60, win[0]%60, win[1]/60, win[1]%60);
	return 0;
}