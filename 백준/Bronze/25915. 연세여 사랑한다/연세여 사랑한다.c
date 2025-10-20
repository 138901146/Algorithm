#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int distance(char x,char y)
{
	return abs(x-y);
}

int main(void)
{
	int total;
	char c;

	scanf("%c", &c);

	total=distance(c,'I');
	total+=distance('I','L');
	total+=distance('L','O');
	total+=distance('O','V');
	total+=distance('V','E');
	total+=distance('E','Y');
	total+=distance('Y','O');
	total+=distance('O','N');
	total+=distance('N','S');
	total+=distance('S','E');
	total+=distance('E','I');

	printf("%d", total);
	return 0;
}