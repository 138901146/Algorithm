#include<stdio.h>

int main(void)
{
	int n, k;

	while(scanf("%d%d", &n, &k)!=EOF)
	{
		int total=n, chicken;

		while(k<=n)
		{
			chicken=n/k;
			n%=k;
			n+=chicken;
			total+=chicken;
		}

		printf("%d\n", total);
	}

	return 0;
}