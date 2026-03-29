#include<stdio.h>

int main(void)
{
	int S1, S2, S3, count[81]={0}, max=0;

	scanf("%d%d%d", &S1, &S2, &S3);

	for(int i=1;i<=S1;++i)
		for(int j=1;j<=S2;++j)
			for(int k=1;k<=S3;++k)
				++count[i+j+k];

	for(int i=1;i<=S1+S2+S3;++i)
		max=count[max]<count[i]?i:max;

	printf("%d", max);
	return 0;
}