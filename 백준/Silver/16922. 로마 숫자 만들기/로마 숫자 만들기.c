#include<stdio.h>
#include<stdbool.h>

int N;
bool digit[1001][21]={false};

void to_rome(int number,int current)
{
	if(current==N)
	{
		digit[number][current]=true;
		return;
	}

	if(!digit[number+1][current+1])
	{
		digit[number+1][current+1]=true;
		to_rome(number+1,current+1);
	}
	if(!digit[number+5][current+1])
	{
		digit[number+5][current+1]=true;
		to_rome(number+5,current+1);
	}
	if(!digit[number+10][current+1])
	{
		digit[number+10][current+1]=true;
		to_rome(number+10,current+1);
	}
	if(!digit[number+50][current+1])
	{
		digit[number+50][current+1]=true;
		to_rome(number+50,current+1);
	}
}

int main(void)
{
	int count=0;

	scanf("%d", &N);

	to_rome(0,0);

	for(int i=1;i<1001;++i)
		count+=digit[i][N];

	printf("%d", count);
	return 0;
}