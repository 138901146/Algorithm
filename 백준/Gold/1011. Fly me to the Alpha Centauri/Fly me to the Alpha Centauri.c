#include<stdio.h>
#include<math.h>

int main(void)
{
	int x, y, T;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &x, &y);

		y-=x;
		x=sqrt(y-1);

		printf("%d\n", (x<<1)+(x*x+x<y));
	}

	return 0;
}