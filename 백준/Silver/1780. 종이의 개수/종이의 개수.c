#include<stdio.h>

int paper[2187][2187], count[3]={0};

void count_paper(int r,int c,int size)
{
	if(size==1)
	{
		++count[paper[r][c]+1];
		return;
	}

	int origin=paper[r][c], same=1;

	for(int i=0;i<size&&same;++i)
		for(int j=0;j<size&&same;++j)
			if(paper[r+i][c+j]!=origin)
				same=0;

	if(same)
		++count[origin+1];
	else
	{
		size/=3;

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				count_paper(r+i*size,c+j*size,size);
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &paper[i][j]);

	count_paper(0,0,N);

	for(int i=0;i<3;++i)
		printf("%d\n", count[i]);
	return 0;
}