#include<stdio.h>
#include<stdbool.h>

bool paper[10][10];
int min=100;

void simulate(int r,int c,bool filled[10][10],int count,int left[5])
{
	for(int i=0;i<5;++i)
		if(5<left[i])
			return;

	if(r==10)
	{
		min=count<min?count:min;
		return;
	}

	if(filled[r][c] || !paper[r][c])
	{
		c==9?simulate(r+1,0,filled,count,left):simulate(r,c+1,filled,count,left);
		return;
	}

	bool attachable=true, current[10][10];

	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			current[i][j]=filled[i][j];

	for(int i=1;i<=5&&attachable&&r+i<=10&&c+i<=10;++i)
	{
		for(int j=0;j<i&&attachable;++j)
			for(int k=0;k<i&&attachable;++k)
				if(!paper[r+j][c+k] || filled[r+j][c+k])
				{
					attachable=false;
					break;
				}

		if(attachable)
		{
			for(int j=0;j<i;++j)
				for(int k=0;k<i;++k)
					current[r+j][c+k]=true;

			++left[i-1];
			c==9?simulate(r+1,0,current,count+1,left):simulate(r,c+1,current,count+1,left);
			--left[i-1];
		}
	}
}

int main(void)
{
	int left[5]={0};
	bool filled[10][10]={0};

	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			scanf("%d", &paper[i][j]);

	simulate(0,0,filled,0,left);

	printf("%d", min==100?-1:min);
	return 0;
}