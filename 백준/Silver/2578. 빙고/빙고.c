#include<stdio.h>
#include<stdbool.h>

bool bingocheck(int bingo[5][5],int num)
{
	int count=0;
	bool checked;

	for(int i=0;i<5;i++)
	{
		checked=false;

		for(int j=0;j<5;j++)
			if(bingo[i][j]==num)
			{
				bingo[i][j]=0;
				checked=true;
				break;
			}

		if(checked)
			break;
	}

	checked=true;
	for(int i=0;i<5;i++)
		if(bingo[i][i]!=0)
		{
			checked=false;
			break;
		}
	count+=checked;

	checked=true;
	for(int i=0;i<5;i++)
		if(bingo[i][4-i]!=0)
		{
			checked=false;
			break;
		}
	count+=checked;

	for(int i=0;i<5;i++)
	{
		checked=true;
		for(int j=0;j<5;j++)
			if(bingo[i][j]!=0)
			{
				checked=false;
				break;
			}
		count+=checked;

		if(count>=3)
			return true;

		checked=true;
		for(int j=0;j<5;j++)
			if(bingo[j][i]!=0)
			{
				checked=false;
				break;
			}
		count+=checked;

		if(count>=3)
			return true;
	}

	return false;
}

int main(void)
{
	int bingo[5][5], number;

	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d", &bingo[i][j]);

	for(int i=1;i<=25;i++)
	{
		scanf("%d", &number);

		if(bingocheck(bingo,number))
		{
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}