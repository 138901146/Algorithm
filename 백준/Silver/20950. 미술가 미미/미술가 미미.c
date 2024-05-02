#include<stdio.h>

int N, R[30], G[30], B[30], gom_R, gom_G, gom_B, min=999;

int abs(int X)
{
	return X<0?-X:X;
}

void paint(int current,int count,int red,int green,int blue)
{
	if(1<count && count<=7)
	{
		int diff=abs(gom_R-red/count)+abs(gom_G-green/count)+abs(gom_B-blue/count);
		min=diff<min?diff:min;

		if(count==7)
			return;
	}

	if(7<count || current==N)
		return;

	paint(current+1,count,red,green,blue);
	paint(current+1,count+1,red+R[current],green+G[current],blue+B[current]);
}

int main(void)
{
	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d%d%d", &R[i], &G[i], &B[i]);
	scanf("%d%d%d", &gom_R, &gom_G, &gom_B);

	paint(0,0,0,0,0);

	printf("%d", min);
	return 0;
}