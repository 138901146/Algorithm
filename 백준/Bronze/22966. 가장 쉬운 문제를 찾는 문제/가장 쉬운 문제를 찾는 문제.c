#include<stdio.h>

int main(void)
{
	int N, level[4], easy=0;
	char title[4][11]={0};

	scanf("%d", &N);

	for(int n=0;n<N;++n)
	{
		scanf("%s%d", title[n], &level[n]);
		easy=level[easy]<level[n]?easy:n;
	}

	printf("%s", title[easy]);
	return 0;
}