#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, R;
	long long *min=NULL;

	scanf("%d", &N);

	if(N==1)
	{
		printf("0");
		return 0;
	}

	min=(long long *)calloc(N,sizeof(long long));

	for(int i=0;i<2;++i)
	{
		scanf("%d", &R);
		min[i]=R;
	}
	for(int i=2;i<N;++i)
	{
		scanf("%d", &R);
		min[i]=min[i-2]<min[i-1]?min[i-2]:min[i-1];
		min[i]+=R;
	}

	printf("%lld", min[N-1]<min[N-2]?min[N-1]:min[N-2]);
	return 0;
}