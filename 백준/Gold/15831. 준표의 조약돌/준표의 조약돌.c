#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, B, W, *white=NULL, left=0, max=0;
	char stone;

	scanf("%d%d%d", &N, &B, &W);
	white=(int *)calloc(N+1,sizeof(int));

	getchar();
	for(int right=1;right<=N;++right)
	{
		stone=getchar();
		white[right]=white[right-1]+(stone=='W');

		while(left<right && B<right-left-white[right]+white[left])
			++left;

		if(W<=white[right]-white[left] && max<right-left)
			max=right-left;
	}

	printf("%d", max);
	free(white);
	return 0;
}