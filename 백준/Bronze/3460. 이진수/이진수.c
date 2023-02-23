#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int n;

		scanf("%d", &n);

		for(int i=0;n>0;i++,n/=2)
			if(n%2==1)
				printf("%d ", i);
		printf("\n");
	}

	return 0;
}