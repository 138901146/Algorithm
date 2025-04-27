#include<stdio.h>

int main(void)
{
	int N, a, b, g, temp, score[3]={0}, origin[3]={0,1,2};

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d%d", &a, &b, &g);

		temp=origin[a-1];
		origin[a-1]=origin[b-1];
		origin[b-1]=temp;

		++score[origin[g-1]];
	}

	temp=0;
	for(int i=0;i<3;++i)
		temp=score[i]<temp?temp:score[i];

	printf("%d", temp);
	return 0;
}