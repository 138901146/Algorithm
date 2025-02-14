#include<stdio.h>

int main(void)
{
	int w, h, n, a, b;

	scanf("%d%d", &w, &h);
	scanf("%d%d%d", &n, &a, &b);

	w/=a;
	h/=b;

	printf("%d", w&&h?n/(w*h)+(n%(w*h)!=0):-1);
	return 0;
}