#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	bool paper[103][103]={false, };
	int N, x, y, length=0;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d%d", &x, &y);

		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				paper[x+i+1][y+j+1]=true;
	}

	for(int i=1;i<102;i++)
		for(int j=1;j<102;j++)
			if(paper[i][j])
			{
				length+=paper[i-1][j]==0;
				length+=paper[i+1][j]==0;
				length+=paper[i][j-1]==0;
				length+=paper[i][j+1]==0;
			}

	printf("%d\n", length);
	return 0;
}