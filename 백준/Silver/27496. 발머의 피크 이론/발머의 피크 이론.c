#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, L, a, count=0;
	long long *C=NULL;

	scanf("%d%d", &N, &L);
	C=(long long *)calloc(N+L+1,sizeof(long long));

	for(int i=1;i<=N;++i)
	{
		scanf("%d", &a);
		C[i]+=C[i-1]+a;
		C[i+L]-=a;
		count+=128<C[i]&&C[i]<139;
	}

	printf("%d", count);
	free(C);
	return 0;
}