#include<stdio.h>

int main(void)
{
	int N, M, selected=0;
	char opinion[100]={0};

	scanf("%d%d", &N, &M);

	while(N--)
	{
		int count=0;

		scanf("%s", opinion);

		for(int m=0;m<M;++m)
			count+=opinion[m]=='O';

		selected+=M<count<<1;
	}

	printf("%d", selected);
	return 0;
}