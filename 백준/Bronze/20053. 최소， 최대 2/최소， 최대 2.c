#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, min=1000000, max=-1000000, num;

		scanf("%d", &N);

		while(N--)
		{
			scanf("%d", &num);

			min=num<min?num:min;
			max=num<max?max:num;
		}

		printf("%d %d\n", min, max);
	}

	return 0;
}