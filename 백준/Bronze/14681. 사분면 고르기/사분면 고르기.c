#include<stdio.h>

int main(void)
{
	int x, y;

	scanf("%d", &x);
	scanf("%d", &y);
	printf("%d", x>0&&y>0?1:x<0&&y>0?2:x<0&&y<0?3:4);

	return 0;
}