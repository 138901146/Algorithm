#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, x=3, **arr=NULL, r, c, state=2, current=1;

	scanf("%d", &N);
	arr=(int **)malloc((N+1)*sizeof(int *));
	for(int n=1;n<=N;++n)
		arr[n]=(int *)malloc((N+1)*sizeof(int));

	r=c=(N>>1)+1;
	arr[r][c]=1;
	arr[--r][c]=2;
	arr[r][++c]=3;
	while(x<N*N)
	{
		current+=state&1^1;
		switch(state)
		{
			case 0:
				for(int i=0;i<current&&x<N*N;++i)
					arr[--r][c]=++x;
				state=1;
				break;
			case 1:
				for(int i=0;i<current&&x<N*N;++i)
					arr[r][++c]=++x;
				state=2;
				break;
			case 2:
				for(int i=0;i<current&&x<N*N;++i)
					arr[++r][c]=++x;
				state=3;
				break;
			case 3:
				for(int i=0;i<current&&x<N*N;++i)
					arr[r][--c]=++x;
				state=0;
				break;
		}
	}

	scanf("%d", &x);

	for(r=1;r<=N;++r)
	{
		for(c=1;c<=N;++c)
			printf("%d ", arr[r][c]);
		printf("\n");
	}

	for(r=1;r<=N;++r)
		for(c=1;c<=N;++c)
			if(arr[r][c]==x)
			{
				printf("%d %d", r, c);
				while(N)
					free(arr[N--]);
				free(arr);
				return 0;
			}

	while(N)
		free(arr[N--]);
	free(arr);
	return 0;
}