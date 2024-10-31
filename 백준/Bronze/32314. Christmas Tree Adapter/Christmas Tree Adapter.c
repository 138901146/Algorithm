#include<stdio.h>

int main(void)
{
	int a, w, v;

	scanf("%d", &a);
	scanf("%d%d", &w, &v);

	printf("%d", a<=w/v);
	return 0;
}