#include<stdio.h>

int main(void)
{
	int N, a[100], b, count=0;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);
	for(int i=0;i<N;++i)
	{
		scanf("%d", &b);

		if(b<a[i])
			count+=a[i]-b;
	}

	printf("%d", count);
	return 0;
}