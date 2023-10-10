#include<stdio.h>
#include<stdbool.h>

int group[7][7], min=100, ball;

void simulate(int index)
{
	if(!min)
		return;

	int next=0, sum=0;
	bool changed=true;

	while(next<7 && !group[next][index])
		++next;
	group[next-1][index]=ball;

	while(changed)
	{
		changed=false;

		for(int i=0;i<7;++i)
			for(int j=0;j<7;++j)
				if(group[i][j]!=0)
				{
					int row=1, col=1;

					for(int k=1;i+k<7 && group[i+k][j]!=0;++k, ++row);
					for(int k=-1;i+k>=0 && group[i+k][j]!=0;--k, ++row);
					for(int k=1;j+k<7 && group[i][j+k]!=0;++k, ++col);
					for(int k=-1;j+k>=0 && group[i][j+k]!=0;--k, ++col);

					if(group[i][j]==row || group[i][j]==col)
					{
						changed=true;
						group[i][j]=-group[i][j];
					}
				}

		if(changed)
		{
			for(int j=0;j<7;++j)
				for(int i=6;i;--i)
					if(group[i][j]<0)
					{
						group[i][j]=0;
						for(int k=i;k;--k)
							group[k][j]=group[k-1][j];
						group[0][j]=0;
						++i;
					}
		}
	}

	for(int i=0;i<7;++i)
		for(int j=0;j<7;++j)
			sum+=group[i][j]>0;

	min=sum<min?sum:min;
}

int main(void)
{
	int init[7][7];

	for(int i=0;i<7;++i)
		for(int j=0;j<7;++j)
			scanf("%d", &init[i][j]);
	scanf("%d", &ball);

	for(int i=0;i<7;++i)
	{
		for(int j=0;j<7;++j)
			for(int k=0;k<7;++k)
				group[j][k]=init[j][k];

		simulate(i);
	}

	printf("%d", min);
	return 0;
}