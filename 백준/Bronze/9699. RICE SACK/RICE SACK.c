#include<stdio.h>

int main(void)
{
	int X;

	scanf("%d", &X);

	for(int x=1;x<=X;++x)
	{
		int rice, max=0;

		for(int i=0;i<5;++i)
		{
			scanf("%d", &rice);
			max=rice<max?max:rice;
		}

		printf("Case #%d: %d\n", x, max);
	}

	return 0;
}