#include<stdio.h>

int main(void)
{
	int Q, a, b, in, out;

	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%d%d", &a, &b);

		if(a<b)
		{
			in=b-a;
			out=a+43-b;
		}
		else
		{
			in=b+43-a;
			out=a-b;
		}

		printf("%s\n", in<out?"Inner circle line":out<in?"Outer circle line":"Same");
	}

	return 0;
}