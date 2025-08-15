#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, L, a, *C=NULL, count=0;

	scanf("%d%d", &N, &L);
	C=(int *)calloc(N+L+1,sizeof(int));

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