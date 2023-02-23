#include<stdio.h>

int main(void)
{
	int n, x, y, Q[5]={0, };

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &x, &y);

		if(x==0 || y==0)
			Q[0]++;
		else if(x>0 && y>0)
			Q[1]++;
		else if(x<0 && y>0)
			Q[2]++;
		else if(x<0 && y<0)
			Q[3]++;
		else
			Q[4]++;
	}

	for(int i=1;i<=4;i++)
		printf("Q%d: %d\n", i, Q[i]);
	printf("AXIS: %d\n", Q[0]);
	return 0;
}