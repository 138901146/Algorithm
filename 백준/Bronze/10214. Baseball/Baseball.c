#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int Y=0, K=0;

		for(int i=0;i<9;i++)
		{
			int y, k;

			scanf("%d %d", &y, &k);

			Y+=y;
			K+=k;
		}

		printf("%s\n", Y>K?"Yonsei":Y<K?"Korea":"Draw");
	}

	return 0;
}