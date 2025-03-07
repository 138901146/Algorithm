#include<stdio.h>

int main(void)
{
	int H, M, D, count=-671;

	scanf("%d%d%d", &H, &M, &D);

	count+=(H-11)*1440;
	count+=M*60;
	count+=D;

	printf("%d", count<0?-1:count);
	return 0;
}