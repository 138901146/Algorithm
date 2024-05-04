#include<stdio.h>
#include<stdbool.h>

char star[5][10]={0};
int star_order[12][2]={{0,4},{1,1},{1,3},{1,5},{1,7},{2,2},{2,6},{3,1},{3,3},{3,5},{3,7},{4,4}}, check_order[6][4]={{0,2,5,7},{0,3,6,10},{1,2,3,4},{1,5,8,11},{4,6,9,11},{7,8,9,10}};
bool fixed[5][9]={false}, done=false;

bool check(void)
{
	int arr[12];

	for(int i=0;i<12;++i)
		arr[i]=star[star_order[i][0]][star_order[i][1]]-'A';

	for(int i=0;i<6;++i)
	{
		int sum=0;

		for(int j=0;j<4;++j)
			sum+=arr[check_order[i][j]];

		if(sum!=22)
			return false;
	}

	return true;
}

void magic(int current,int status)
{
	if(done)
		return;
	if(status==4095)
	{
		done=check();
		return;
	}
	if(fixed[star_order[current][0]][star_order[current][1]])
	{
		magic(current+1,status);
		return;
	}
	for(int i=0;i<12 && !done;++i)
		if(!(status&(1<<i)))
		{
			star[star_order[current][0]][star_order[current][1]]=i+'A';
			magic(current+1,1<<i|status);
		}
}

int main(void)
{
	int flag=0;

	for(int i=0;i<5;++i)
	{
		scanf("%s", star[i]);

		for(int j=0;j<9;++j)
			if('A'<=star[i][j] && star[i][j]<='L')
			{
				fixed[i][j]=true;
				flag|=1<<star[i][j]-'A';
			}
	}

	magic(0,flag);

	for(int i=0;i<5;++i)
		printf("%s\n", star[i]);
	return 0;
}