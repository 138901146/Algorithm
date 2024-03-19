#include<stdio.h>

int main(void)
{
	char s;

	s=getchar();

	printf("%s", s=='N'?"North London Collegiate School":s=='B'?"Branksome Hall Asia":s=='K'?"Korea International School":"St. Johnsbury Academy");
	return 0;
}