#include<stdio.h>

int main(void)
{
	int N, three[2][3]={0}, current=0, previous=1;

	scanf("%d", &N);

	three[1][1]=three[1][2]=1;

	while(--N)
	{
		for(int i=0;i<3;++i)
		{
			three[current][i]=0;

			for(int j=0;j<3;++j)
				three[current][i]=(three[current][i]+three[previous][j])%1000000009;
		}

		current^=1;
		previous^=1;
	}

	printf("%d", three[previous][0]);
	return 0;
}