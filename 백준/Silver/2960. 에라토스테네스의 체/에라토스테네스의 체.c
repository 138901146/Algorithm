#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, K, count=0;
	bool *sieve=NULL, reached=false;

	scanf("%d %d", &N, &K);
	sieve=(bool *)calloc(N+1,sizeof(bool));

	for(int i=2;;i++)
	{
		if(!sieve[i])
			for(int j=1;i*j<=N;j++)
			{
				if(!sieve[i*j])
				{
					sieve[i*j]=true;
					count++;
				}

				if(count==K)
				{
					reached=true;
					printf("%d\n", i*j);
					free(sieve);
					break;
				}
			}
		if(reached)
			break;
	}

	return 0;
}