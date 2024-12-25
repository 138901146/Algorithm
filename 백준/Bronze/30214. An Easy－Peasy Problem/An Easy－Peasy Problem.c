#include<stdio.h>

int main(void)
{
	int s1, s2;

	scanf("%d%d", &s1, &s2);

	printf("%c", s2<=(s1<<1)?'E':'H');
	return 0;
}