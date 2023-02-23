#include<stdio.h>
#include<stdlib.h>

int N, S[10], B[10];

int food(int current,int set)
{
	if(current==N)
	{
		if(set>0)
		{
			int s=1, b=0;

			for(int n=0;n<N;n++)
				if(set & 1<<n)
				{
					s*=S[n];
					b+=B[n];
				}

			return s-b>=0?s-b:b-s;
		}
		return 1000000000;
	}

	int used=food(current+1,set|1<<current);
	int unused=food(current+1,set);

	return used<unused?used:unused;
}

int main(void)
{
	scanf("%d", &N);

	for(int n=0;n<N;n++)
		scanf("%d%d", &S[n], &B[n]);

	printf("%d\n", food(0,0));
	return 0;
}