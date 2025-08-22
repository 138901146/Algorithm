#include<stdio.h>
#include<stdlib.h>

int **seat=NULL;

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int prize(int r_s,int c_s,int r_e,int c_e)
{
	if(r_s==r_e&&c_s==c_e)
		return seat[r_s][c_s];

	int r_m=r_s+r_e>>1, c_m=c_s+c_e>>1, number[4]={prize(r_s,c_s,r_m,c_m),prize(r_s,c_m+1,r_m,c_e),prize(r_m+1,c_s,r_e,c_m),prize(r_m+1,c_m+1,r_e,c_e)};

	qsort((void *)number,(size_t)4,sizeof(int),compare);

	return number[1];
}

int main(void)
{
	int N;

	scanf("%d", &N);
	seat=(int **)malloc(N*sizeof(int *));

	for(int i=0;i<N;++i)
	{
		seat[i]=(int *)malloc(N*sizeof(int));
		for(int j=0;j<N;++j)
			scanf("%d", &seat[i][j]);
	}

	printf("%d", prize(0,0,N-1,N-1));
	while(N)
		free(seat[--N]);
	free(seat);
	return 0;
}