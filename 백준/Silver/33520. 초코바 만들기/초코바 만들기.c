#include<stdio.h>

int main(void)
{
	int N, a, b, W=0, H=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &a, &b);
		if(b<a)
		{
			int temp=a;
			a=b;
			b=temp;
		}

		W=a<W?W:a;
		H=b<H?H:b;
	}

	printf("%lld", (long long)W*H);
	return 0;
}