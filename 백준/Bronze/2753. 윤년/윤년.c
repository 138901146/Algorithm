#include<stdio.h>

int main(void)
{
	int year;

	scanf("%d", &year);
	printf("%d", year%400==0||year%100!=0&&year%4==0?1:0);

	return 0;
}