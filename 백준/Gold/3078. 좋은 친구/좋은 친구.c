#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main(void)
{
	int N, K, friend[21]={0, }, *length=NULL;
	long long sum=0;
	char name[21]={'\0', };

	scanf("%d%d", &N, &K);
	length=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%s", name);
		length[n]=strlen(name);

		if(n>K)
			friend[length[n-K-1]]--;

		sum+=friend[length[n]];
		friend[length[n]]++;
	}

	printf("%lld", sum);
	free(length);
	return 0;
}