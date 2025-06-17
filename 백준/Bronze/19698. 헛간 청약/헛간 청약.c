#include<stdio.h>

int main(void)
{
	int N, W, H, L;

	scanf("%d%d%d%d", &N, &W, &H, &L);

	W/=L;
	H/=L;

	printf("%d", W*H<N?W*H:N);
	return 0;
}