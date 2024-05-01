#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int id, score;
}
rank;

int compare(const void *x,const void *y)
{
	return ((rank *)x)->score<((rank *)y)->score?1:((rank *)x)->score>((rank *)y)->score?-1:((rank *)x)->id<((rank *)y)->id?-1:1;
}

int main(void)
{
	int N, winner[4];
	rank *korean=NULL, *english=NULL, *math=NULL, *science=NULL;
	bool *award=NULL;

	scanf("%d", &N);
	korean=(rank *)malloc(N*sizeof(rank));
	english=(rank *)malloc(N*sizeof(rank));
	math=(rank *)malloc(N*sizeof(rank));
	science=(rank *)malloc(N*sizeof(rank));
	award=(bool *)calloc(N+1,sizeof(bool));

	for(int n=0;n<N;++n)
	{
		scanf("%d%d%d%d%d", &korean[n].id, &korean[n].score, &english[n].score, &math[n].score, &science[n].score);
		english[n].id=math[n].id=science[n].id=korean[n].id;
	}
	qsort((void *)korean,(size_t)N,sizeof(rank),compare);
	qsort((void *)english,(size_t)N,sizeof(rank),compare);
	qsort((void *)math,(size_t)N,sizeof(rank),compare);
	qsort((void *)science,(size_t)N,sizeof(rank),compare);

	winner[0]=korean[0].id;
	award[winner[0]]=true;

	for(int n=0;n<N;++n)
		if(!award[english[n].id])
		{
			winner[1]=english[n].id;
			award[winner[1]]=true;
			break;
		}

	for(int n=0;n<N;++n)
		if(!award[math[n].id])
		{
			winner[2]=math[n].id;
			award[winner[2]]=true;
			break;
		}

	for(int n=0;n<N;++n)
		if(!award[science[n].id])
		{
			winner[3]=science[n].id;
			award[winner[3]]=true;
			break;
		}

	for(int i=0;i<4;++i)
		printf("%d ", winner[i]);
	free(korean);
	free(english);
	free(math);
	free(science);
	free(award);
	return 0;
}