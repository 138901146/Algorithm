#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int s, n, total, q, p;

		scanf("%d", &s);
		scanf("%d", &n);
		total=s;

		for(int i=0;i<n;i++)
		{
			scanf("%d %d", &q, &p);
			total+=q*p;
		}

		printf("%d\n", total);
	}

	return 0;
}