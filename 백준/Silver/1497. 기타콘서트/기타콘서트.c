#include<stdio.h>

int N, M, min=50;
long long playable[50]={0}, full=0;

void simulate(int current,long long flag,int count)
{
	if(flag==full)
	{
		min=count<min?count:min;
		return;
	}

	if(current==N)
		return;

	if((flag^full)&playable[current])
		simulate(current+1,flag|playable[current],count+1);

	simulate(current+1,flag,count);
}

int main(void)
{
	char name[51]={0}, song[51]={0};

	scanf("%d%d", &N, &M);

	getchar();
	for(int n=0;n<N;++n)
	{
		scanf("%s%s", name, song);

		for(int m=0;m<M;++m)
			if(song[m]=='Y')
				playable[n]|=(long long)1<<m;
		full|=playable[n];
	}

	if(!full)
	{
		printf("-1");
		return 0;
	}

	simulate(0,0,0);

	printf("%d", min);
	return 0;
}