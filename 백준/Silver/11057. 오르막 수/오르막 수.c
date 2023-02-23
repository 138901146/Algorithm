#include<stdio.h>

int main(void)
{
	int N, prev[10]={1, }, current[10], sum=0;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		for(int i=0;i<10;i++)
		{
			current[i]=0;
			for(int j=0;j<=i;j++)
				current[i]+=prev[j];
		}

		for(int i=0;i<10;i++)
			prev[i]=current[i]%10007;
	}

	for(int i=0;i<10;i++)
		sum+=current[i];

	printf("%d\n", sum%10007);
	return 0;
}