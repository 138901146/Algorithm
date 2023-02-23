#include<stdio.h>
#include<stdbool.h>

bool fullcheck(int paper[])
{
	for(int i=0;i<10;i++)
		if(paper[i]!=(i%5)+1)
			return false;
	return true;
}

int main(void)
{
	int N, full_score=0;

	scanf("%d", &N);

	for(int i=1;i<=N;i++)
	{
		int paper[10];

		for(int j=0;j<10;j++)
			scanf("%d", &paper[j]);

		if(fullcheck(paper))
			printf("%d\n", i);
	}

	return 0;
}