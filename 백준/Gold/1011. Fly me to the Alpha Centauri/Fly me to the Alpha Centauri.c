#include<stdio.h>
#include<math.h>

int main(void)
{
	int x, y, root=0, T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d%d", &x, &y);

		y-=x;
		x=0;
		root=(int)sqrt(y-1);

		printf("%d\n", 2*root+(root*root+root<y));
	}
	return 0;
}