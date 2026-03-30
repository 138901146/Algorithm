#include<stdio.h>

int main(void)
{
	int T, N[5];

	scanf("%d", &T);

	while(T--)
	{
		int score, count[11]={0}, N[5];

		for(int i=0;i<5;++i)
		{
			scanf("%d", &score);
			++count[score];
		}

		score=0;
		for(int i=1;i<11;++i)
			while(count[i]--)
				N[score++]=i;

		if(N[1]+3<N[3])
			printf("KIN\n");
		else
			printf("%d\n", N[1]+N[2]+N[3]);
	}

	return 0;
}