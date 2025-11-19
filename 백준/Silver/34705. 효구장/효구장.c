#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int X, Y, a[5];
		bool enterable=false;

		scanf("%d%d", &X, &Y);
		for(int i=0;i<5;++i)
			scanf("%d", &a[i]);

		for(int i=1;i<32;++i)
		{
			int sum=0;

			for(int j=0;j<5;++j)
				if((1<<j)&i)
					sum+=a[j];

			if(X<=sum&&sum<=Y)
			{
				enterable=true;
				break;
			}
		}

		printf("%s\n", enterable?"YES":"NO");
	}

	return 0;
}