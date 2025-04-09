#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, p[5], k, t[5][1000], count[5]={0}, total=0;

	scanf("%d", &N);
	for(int i=0;i<5;++i)
		scanf("%d", &p[i]);
	while(N--)
	{
		scanf("%d", &k);
		scanf("%d", &t[k-1][count[k-1]++]);
	}

	for(int i=0;i<5;++i)
		qsort((void *)t[i],(size_t)count[i],sizeof(int),compare);

	for(int i=0;i<5;++i)
	{
		total+=t[i][0];
		for(int j=1;j<p[i];++j)
			total+=2*t[i][j]-t[i][j-1];
	}

	printf("%d", total+240);
	return 0;
}