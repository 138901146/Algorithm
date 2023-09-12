#include<stdio.h>

int main(void)
{
	int N, stone, left=0, max=0, right=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &stone);
		left+=stone==1?1:-1;
		right+=stone==2?1:-1;
		left=left>0?left:0;
		right=right>0?right:0;
		max=left>max?left:max;
		max=right>max?right:max;
	}

	printf("%d", max);
	return 0;
}