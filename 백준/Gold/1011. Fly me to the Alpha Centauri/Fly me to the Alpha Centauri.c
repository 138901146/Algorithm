#include<stdio.h>
#include<math.h>

int main(void)
{
	int x, y, root, T;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &x, &y);

		y-=x;
		root=sqrt(y-1);

		printf("%d\n", (root<<1)+(root*root+root<y));
	}

	return 0;
}