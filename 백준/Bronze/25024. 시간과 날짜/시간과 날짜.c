#include<stdio.h>

int is_date(int x,int y)
{
	switch(x)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 0<y&&y<32;
		case 4:
		case 6:
		case 9:
		case 11:
			return 0<y&&y<31;
		case 2:
			return 0<y&&y<30;
		default:
			return 0;
	}

	return 0;
}

int main(void)
{
	int T, x, y;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &x, &y);
		printf("%s %s\n", x<24&&y<60?"Yes":"No", is_date(x,y)?"Yes":"No");
	}

	return 0;
}