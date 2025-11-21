#include<stdio.h>

int main(void)
{
	int N, M, O, P, solvable[10]={0}, max=11;

	scanf("%d%d", &N, &M);

	for(int i=0;i<M;++i)
	{
		scanf("%d", &O);
		while(O--)
		{
			scanf("%d", &P);
			solvable[i]|=1<<P-1;
		}
	}

	for(int i=1;i<(1<<M);++i)
	{
		int solved=0, count=0;

		for(int j=0;j<M;++j)
			if(1<<j&i)
			{
				++count;
				solved|=solvable[j];
			}

		if(solved==(1<<N)-1)
			max=count<max?count:max;
	}

	printf("%d", max==11?-1:max);
	return 0;
}