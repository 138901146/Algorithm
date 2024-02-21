#include<stdio.h>

int main(void)
{
	int N, bigdata=0, security=0;
	char c;

	scanf("%d", &N);
	getchar();

	while(N--)
	{
		c=getchar();

		if(c=='s')
		{
			++security;
			for(int i=0;i<7;++i)
				getchar();
		}
		else
		{
			++bigdata;
			for(int i=0;i<6;++i)
				getchar();
		}
	}

	printf("%s", security<bigdata?"bigdata?":bigdata<security?"security!":"bigdata? security!");
	return 0;
}