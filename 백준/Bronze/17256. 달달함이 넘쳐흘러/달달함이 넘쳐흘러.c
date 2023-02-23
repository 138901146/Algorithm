#include<stdio.h>

int main(void)
{
	int a[3], c[3];

	for(int i=0;i<3;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<3;i++)
		scanf("%d", &c[i]);

	printf("%d %d %d\n", c[0]-a[2], c[1]/a[1], c[2]-a[0]);
	return 0;
}