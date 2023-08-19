#include<stdio.h>

int main(void)
{
	int n;
	long long sum=0, number=0;
	char c;

	scanf("%d", &n);
	getchar();

	while(n--)
	{
		scanf("%c", &c);

		if(c>='0' && c<='9')
		{
			number*=10;
			number+=c-'0';
		}
		else
		{
			sum+=number;
			number=0;
		}
	}

	printf("%lld\n", sum+number);
	return 0;
}