#include<stdio.h>

int main(void)
{
	int N, r, c, x=0, y=0, order=0;

	scanf("%d%d%d", &N, &r, &c);

	N--;
	while(x!=r || y!=c)
	{
		int shift=1<<N;
		if(x+shift<=r && y+shift<=c)
		{
			order+=3*shift*shift;
			x+=shift;
			y+=shift;
		}
		else if(x+shift<=r)
		{
			order+=2*shift*shift;
			x+=shift;
		}
		else if(y+shift<=c)
		{
			order+=shift*shift;
			y+=shift;
		}
		N--;
	}

	printf("%d\n", order);
	return 0;
}