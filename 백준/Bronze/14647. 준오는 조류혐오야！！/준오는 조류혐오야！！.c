#include<stdio.h>

int main(void)
{
	int n, m, bingo[500][500], max=0, total=0;

	scanf("%d%d", &n, &m);

	for(int r=0;r<n;++r)
		for(int c=0;c<m;++c)
			scanf("%d", &bingo[r][c]);

	for(int r=0;r<n;++r)
		for(int c=0;c<m;++c)
		{
			int temp=bingo[r][c];

			while(temp)
			{
				total+=temp%10==9;
				temp/=10;
			}
		}

	for(int r=0;r<n;++r)
	{
		int count=0, temp;

		for(int c=0;c<m;++c)
		{
			int temp=bingo[r][c];

			while(temp)
			{
				count+=temp%10==9;
				temp/=10;
			}
		}

		max=count<max?max:count;
	}

	for(int c=0;c<m;++c)
	{
		int count=0, temp;

		for(int r=0;r<n;++r)
		{
			int temp=bingo[r][c];

			while(temp)
			{
				count+=temp%10==9;
				temp/=10;
			}
		}

		max=count<max?max:count;
	}

	printf("%d", total-max);
	return 0;
}