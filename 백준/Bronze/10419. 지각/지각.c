#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int d, s=0;

		scanf("%d", &d);

		while(s+s*s<=d)
			s++;

		printf("%d\n", s-1);
	}

	return 0;
}