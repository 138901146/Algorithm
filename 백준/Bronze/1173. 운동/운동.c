#include<stdio.h>

int main(void)
{
	int N, m, M, T, R, count=0, current;

	scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);

	if(M<m+T)
	{
		printf("-1");
		return 0;
	}

	current=m;
	while(N)
	{
		if(current+T<=M)
		{
			current+=T;
			--N;
		}
		else
			current=current-R<m?m:current-R;

		++count;
	}

	printf("%d", count);
	return 0;
}