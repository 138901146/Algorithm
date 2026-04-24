#include<stdio.h>
#include<stdlib.h>

#define INF 123456789

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, S[100], min[10001];

	scanf("%d%d", &N, &M);

	for(int i=0;i<M;++i)
		scanf("%d", &S[i]);

	qsort((void *)S,(size_t)M,sizeof(int),compare);

	min[0]=0;
	for(int i=1;i<=N;++i)
		min[i]=INF;

	for(int i=0;i<=N;++i)
		for(int j=0;j<M;++j)
		{
			if(i+S[j]<=N)
				min[i+S[j]]=min[i]+1<min[i+S[j]]?min[i]+1:min[i+S[j]];
			else
				break;
			for(int k=j+1;k<M;++k)
				if(i+S[j]+S[k]<=N)
					min[i+S[j]+S[k]]=min[i]+1<min[i+S[j]+S[k]]?min[i]+1:min[i+S[j]+S[k]];
				else
					break;
		}

	printf("%d", min[N]==INF?-1:min[N]);
	return 0;
}