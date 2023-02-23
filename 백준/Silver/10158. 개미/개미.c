#include<stdio.h>

int main(void)
{
	int w, h, p, q, t;

	scanf("%d%d", &w, &h);
	scanf("%d%d", &p, &q);
	scanf("%d", &t);

	int x=t%(2*w), y=t%(2*h);

	while(x>0 && p<w)
	{
		x--;
		p++;
	}
	while(x>0 && p>0)
	{
		x--;
		p--;
	}
	while(x>0 && p<w)
	{
		x--;
		p++;
	}
	while(y>0 && q<h)
	{
		y--;
		q++;
	}
	while(y>0 && q>0)
	{
		y--;
		q--;
	}
	while(y>0 && q<h)
	{
		y--;
		q++;
	}

	printf("%d %d\n",  p, q);
	return 0;
}