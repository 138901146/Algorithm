#include<stdio.h>

int min(int x,int y,int z)
{
	return x<=z&&x<=y?x:y<=x&&y<=z?y:z;
}

int main(void)
{
	int y, c, p;

	scanf("%d%d%d", &y, &c, &p);

	printf("%d", min(y,c>>1,p));
	return 0;
}