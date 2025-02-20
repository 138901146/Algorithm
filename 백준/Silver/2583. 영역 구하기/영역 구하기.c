#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int M, N, K, x1, x2, y1, y2, id[100][100]={0}, count=0, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, queue[10000], size[10000];

	scanf("%d%d%d", &M, &N, &K);

	while(K--)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		for(int x=x1;x<x2;++x)
			for(int y=y1;y<y2;++y)
				id[y][x]=-1;
	}

	for(int m=0;m<M;++m)
		for(int n=0;n<N;++n)
			if(!id[m][n])
			{
				int front=0, rear=1;

				id[m][n]=++count;
				queue[0]=m<<7|n;

				while(front<rear)
				{
					int r=queue[front]>>7, c=queue[front]&127;

					for(int i=0;i<4;++i)
					{
						int nr=r+dr[i], nc=c+dc[i];

						if(nr<0 || M<=nr || nc<0 || N<=nc || id[nr][nc])
							continue;

						id[nr][nc]=count;
						queue[rear++]=nr<<7|nc;
					}

					++front;
				}

				size[count-1]=rear;
			}

	qsort((void *)size,(size_t)count,sizeof(int),compare);

	printf("%d\n", count);
	for(int i=0;i<count;++i)
		printf("%d ", size[i]);
	return 0;
}