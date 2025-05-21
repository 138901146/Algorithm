#include<stdio.h>

int main(void)
{
	int N, x_min, y_min=1001, x, y;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &x, &y);

		if(y<y_min)
		{
			x_min=x;
			y_min=y;
		}
	}

	printf("%d %d", x_min, y_min);
	return 0;
}