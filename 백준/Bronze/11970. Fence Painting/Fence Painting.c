#include<stdio.h>

int main(void)
{
	int a, b, c, d, count=0, painted[101]={0};

	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);

	for(int i=a;i<b;++i)
		painted[i]=1;
	for(int i=c;i<d;++i)
		painted[i]=1;

	for(int i=0;i<101;++i)
		count+=painted[i];

	printf("%d", count);
	return 0;
}