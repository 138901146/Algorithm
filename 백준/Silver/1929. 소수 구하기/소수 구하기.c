#include<stdio.h>
#include<stdbool.h>

bool prime[1000002]={false};

int main(void)
{
	int M, N;

	scanf("%d%d", &M, &N);

	for(int n=N|1;n>2;n-=2)
		prime[n]=true;

	if(M<3)
		printf("2\n");
	for(int i=3;i<=N;i+=2)
		if(prime[i])
		{
			if(M<=i)
				printf("%d\n", i);

			if(i*i<=N)
				for(int j=i<<1;j<=N;j+=i)
					prime[j]=false;
		}

	return 0;
}