#include<stdio.h>

int main(void)
{
	int antenna, eye;

	scanf("%d", &antenna);
	scanf("%d", &eye);

	if(2<antenna && eye<5)
		printf("TroyMartian\n");
	if(1<eye && antenna<7)
		printf("VladSaturnian\n");
	if(antenna<3 && eye<4)
		printf("GraemeMercurian\n");

	return 0;
}