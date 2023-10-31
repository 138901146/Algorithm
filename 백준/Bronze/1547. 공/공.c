#include<stdio.h>

int main(void)
{
	int ball[4]={0,1,0,0}, M, X, Y;

	scanf("%d", &M);

	while(M--)
	{
		scanf("%d%d", &X, &Y);

		int temp=ball[X];
		ball[X]=ball[Y];
		ball[Y]=temp;
	}

	for(int i=1;i<4;++i)
		if(ball[i])
			printf("%d", i);
	return 0;
}