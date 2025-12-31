#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int R, C, **V=NULL, T, count=0, filter[9];

	scanf("%d%d", &R, &C);
	V=(int **)malloc(R*sizeof(int *));
	for(int r=0;r<R;++r)
	{
		V[r]=(int *)malloc(C*sizeof(int));
		for(int c=0;c<C;++c)
			scanf("%d", &V[r][c]);
	}
	scanf("%d", &T);

	for(int r=2;r<R;++r)
	{
		for(int c=2;c<C;++c)
		{
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					filter[3*i+j]=V[r-i][c-j];

			qsort((void *)filter,(size_t)9,sizeof(int),compare);
			count+=T<=filter[4];
		}

		free(V[r-2]);
	}

	printf("%d", count);
	free(V[R-2]);
	free(V[R-1]);
	free(V);
	return 0;
}