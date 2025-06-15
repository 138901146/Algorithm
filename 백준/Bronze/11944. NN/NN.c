#include<stdio.h>

int main(void)
{
	char str[5]={0};
	int N, M, length=0;

	scanf("%d%d", &N, &M);
	sprintf(str, "%d", N);

	while('0'<=str[length]&&str[length]<='9')
		++length;

	if(N*length<=M)
		for(int n=0;n<N;++n)
			printf("%d", N);
	else
		for(int m=0;m<M;++m)
			printf("%c", str[m%length]);
	return 0;
}