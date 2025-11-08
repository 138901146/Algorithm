#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int P, M, C, X, min=2000000000;

	scanf("%d%d%d", &P, &M, &C);
	scanf("%d", &X);

	for(int p=1;p<=P;++p)
		for(int m=1;m<=M;++m)
			for(int c=1;c<=C;++c)
			{
				int pmc=abs((p+m)*(m+c)-X);
				min=pmc<min?pmc:min;
			}

	printf("%d", min);
	return 0;
}