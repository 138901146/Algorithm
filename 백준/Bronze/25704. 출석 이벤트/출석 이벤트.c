#include<stdio.h>

int min(int x,int y)
{
	return x<y?x:y;
}

int max(int x,int y)
{
	return x<y?y:x;
}

int main(void)
{
	int N, P;

	scanf("%d", &N);
	scanf("%d", &P);

	printf("%d", min(14<N?max(P-2000,0):4<N?max(P-500,0):P,19<N?P*3/4:9<N?P*9/10:P));
	return 0;
}