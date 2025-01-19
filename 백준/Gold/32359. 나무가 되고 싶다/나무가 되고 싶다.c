#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INF 1152921504606846975

int N, count=0;
long long *V=NULL;

int compare(const void *x,const void *y)
{
	return *(long long *)x>*(long long *)y?1:-1;
}

bool recursion(long long node)
{
	int left=0, right=N-1;

	while(left<right)
	{
		int mid=left+right>>1;

		if(V[mid]<node)
			left=mid+1;
		else if(node<V[mid])
			right=mid-1;
		else
			break;
	}

	if(V[left+right>>1]==node)
		return true;

	++count;

	if(INF<node || !recursion(node<<1) || !recursion(node<<1|1))
		return false;

	return true;
}

int main(void)
{
	scanf("%d", &N);
	V=(long long *)malloc(N*sizeof(long long));

	for(int i=0;i<N;++i)
		scanf("%lld", &V[i]);
	qsort((void *)V,(size_t)N,sizeof(long long),compare);

	printf("%d", recursion(1)?count:-1);
	free(V);
	return 0;
}