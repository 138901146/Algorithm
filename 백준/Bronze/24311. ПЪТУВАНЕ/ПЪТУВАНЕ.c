#include<stdio.h>

int main(void)
{
	int t1, t2, t3, t4, t5, br, t6, t;

	scanf("%d%d", &t1, &t2);
	scanf("%d", &t3);
	scanf("%d%d", &t4, &t5);
	scanf("%d", &br);
	scanf("%d", &t6);

	t=t1*60+t2-t3-t4*60-t5-(br+1)*t6-10;

	printf("%02d %02d", t/60, t%60);
	return 0;
}