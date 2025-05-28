#include<stdio.h>

int integer(int x)
{
	return x<0?0:x;
}

int main(void)
{
	int Ca, Ba, Pa, Cr, Br, Pr;

	scanf("%d%d%d", &Ca, &Ba, &Pa);
	scanf("%d%d%d", &Cr, &Br, &Pr);

	printf("%d", integer(Cr-Ca)+integer(Br-Ba)+integer(Pr-Pa));
	return 0;
}