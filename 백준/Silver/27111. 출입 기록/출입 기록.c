#include<stdio.h>
#include<stdbool.h>

bool in[200001]={false};

int main(void)
{
	int N, a, b, count=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &a, &b);

		count+=!(in[a]^b);
		in[a]=b;
	}

	for(int i=1;i<200001;++i)
		count+=in[i];

	printf("%d", count);
	return 0;
}