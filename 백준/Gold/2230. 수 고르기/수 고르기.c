#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *A=NULL, left=0, right=1, min=2000000001;

	scanf("%d%d", &N, &M);
	A=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);
	qsort((void *)A,(size_t)N,sizeof(int),compare);

	while(left<N-1)
	{
		int diff=A[right]-A[left];

		if(right==N-1 && diff<M)
			break;

		if(diff<M)
			++right;
		else if(M<diff)
		{
			min=diff<min?diff:min;
			if(++left==right)
				++right;
		}
		else
		{
			min=diff;
			break;
		}
	}

	printf("%d", min);
	free(A);
	return 0;
}