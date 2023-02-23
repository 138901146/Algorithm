#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int H, W, N, X=0, Y=0;
		scanf("%d %d %d", &H, &W, &N);

		for(int j=0;j<N;j++)
		{
			Y++;
			Y=Y==H+1?1:Y;
			X+=j%H==0;
		}

		printf("%d\n", 100*Y+X);
	}

	return 0;
}