#include<stdio.h>

int main(void)
{
	int T, a, b, c;

	scanf("%d", &T);

	while(T--)
	{
		int count=0;

		scanf("%d%d%d", &a, &b, &c);

		for(int x=1;x<=a;++x)
			for(int y=1;y<=b;++y)
				for(int z=1;z<=c;++z)
					count+=x%y==y%z&&y%z==z%x;

		printf("%d\n", count);
	}

	return 0;
}