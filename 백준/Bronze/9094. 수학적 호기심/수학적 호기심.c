#include<stdio.h>

int main(void)
{
	int T, n, m;

	scanf("%d", &T);

	while(T--)
	{
		int count=0;

		scanf("%d%d", &n, &m);

		for(int a=1;a<n;++a)
			for(int b=a+1;b<n;++b)
				count+=!((a*a+b*b+m)%(a*b));

		printf("%d\n", count);
	}

	return 0;
}