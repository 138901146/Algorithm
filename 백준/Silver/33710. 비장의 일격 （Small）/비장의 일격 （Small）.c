#include<stdio.h>
#include<memory.h>

int min=10000, N, K;
char S[101]={0};

void simulate(int current, int start, int sum)
{
	min=N-sum<min?N-sum:min;

	if(current==K)
		return;

	for(int i=start;i<N;++i)
		if(S[i]!='X')
		{
			for(int j=i+1;j<N;++j)
				if(S[i]==S[j])
					simulate(current+1, j+1, sum+j-i+1);
		}
}

int main(void)
{
	scanf("%d%d", &N, &K);
	scanf("%s", S);

	simulate(0, 0, 0);

	printf("%d", N<min?N:min);
	return 0;
}