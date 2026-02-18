#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int N, matrix[1024][1024];

void pooling(void)
{
	if(N==1)
		return;

	for(int r=0;r<N;r+=2)
		for(int c=0;c<N;c+=2)
		{
			int target[4]={matrix[r][c], matrix[r][c+1], matrix[r+1][c], matrix[r+1][c+1]};

			qsort((void *)target,(size_t)4,sizeof(int),compare);

			matrix[r>>1][c>>1]=target[2];
		}

	N>>=1;
	pooling();
}

int main(void)
{
	scanf("%d", &N);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			scanf("%d", &matrix[r][c]);

	pooling();

	printf("%d", matrix[0][0]);
	return 0;
}