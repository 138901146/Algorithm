#include<stdio.h>

int main(void)
{
	for(int i=0;i<3;i++)
	{
		int time[2][3];

		for(int j=0;j<2;j++)
			for(int k=0;k<3;k++)
				scanf("%d", &time[j][k]);
		for(int j=0;j<3;j++)
			time[1][j]-=time[0][j];
		for(int j=2;j>0;j--)
			while(time[1][j]<0)
			{
				time[1][j]+=60;
				time[1][j-1]--;
			}

		printf("%d %d %d\n", time[1][0], time[1][1], time[1][2]);
	}

	return 0;
}