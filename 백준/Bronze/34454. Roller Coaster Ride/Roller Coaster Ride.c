#include<stdio.h>

int main(void)
{
	int N, C, P;

	scanf("%d", &N);
	scanf("%d", &C);
	scanf("%d", &P);

	printf("%s", C*P<N?"no":"yes");
	return 0;
}