#include<stdio.h>

int main(void)
{
	char c;

	scanf("%c", &c);

	printf("%s", c=='M'?"MatKor":c=='W'?"WiCys":c=='C'?"CyKor":c=='A'?"AlKor":"$clear");
	return 0;
}