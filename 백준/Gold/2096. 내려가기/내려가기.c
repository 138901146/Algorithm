#include<stdio.h>
#include<stdlib.h>

int max3(int x,int y,int z)
{
	if(x>=y&&x>=z)
		return x;
	else if(y>=x&&y>=z)
		return y;
	else
		return z;
}

int min3(int x,int y,int z)
{
	if(x<=y&&x<=z)
		return x;
	else if(y<=x&&y<=z)
		return y;
	else
		return z;
}

int main(void)
{
	int N, score[2][3], max[2][3], min[2][3];

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
			scanf("%d", &score[i%2][j]);
		if(i==0)
		{
			for(int j=0;j<3;j++)
				max[i][j]=min[i][j]=score[i][j];
			continue;
		}

		max[i%2][0]=score[i%2][0]+(max[(i-1)%2][0]>max[(i-1)%2][1]?max[(i-1)%2][0]:max[(i-1)%2][1]);
		max[i%2][1]=score[i%2][1]+max3(max[(i-1)%2][0],max[(i-1)%2][1],max[(i-1)%2][2]);
		max[i%2][2]=score[i%2][2]+(max[(i-1)%2][1]>max[(i-1)%2][2]?max[(i-1)%2][1]:max[(i-1)%2][2]);

		min[i%2][0]=score[i%2][0]+(min[(i-1)%2][0]<min[(i-1)%2][1]?min[(i-1)%2][0]:min[(i-1)%2][1]);
		min[i%2][1]=score[i%2][1]+min3(min[(i-1)%2][0],min[(i-1)%2][1],min[(i-1)%2][2]);
		min[i%2][2]=score[i%2][2]+(min[(i-1)%2][1]<min[(i-1)%2][2]?min[(i-1)%2][1]:min[(i-1)%2][2]);
	}

	printf("%d %d\n", max3(max[(N-1)%2][0],max[(N-1)%2][1],max[(N-1)%2][2]), min3(min[(N-1)%2][0], min[(N-1)%2][1], min[(N-1)%2][2]));

	return 0;
}