#include<stdio.h>

int main(void)
{
	int t, sum=0;

	for(int i=0;i<4;++i)
	{
		scanf("%d", &t);
		sum+=t;
	}

	printf("%s", sum<1501?"Yes":"No");
	return 0;
}