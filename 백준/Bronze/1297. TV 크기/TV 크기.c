#include<stdio.h>

int main(void)
{
	int diagonal, hor, ver;
	float hor_temp, ver_temp, rate;

	scanf("%d %d %d", &diagonal, &hor, &ver);

	diagonal*=diagonal;
	hor_temp=(float)hor*hor;
	ver_temp=(float)ver*ver;
	rate=diagonal/(hor_temp+ver_temp);
	hor_temp*=rate;
	ver_temp*=rate;

	for(hor=0;hor*hor<=hor_temp;hor++);
	for(ver=0;ver*ver<=ver_temp;ver++);
	hor--;
	ver--;

	printf("%d %d\n", hor, ver);
	return 0;
}