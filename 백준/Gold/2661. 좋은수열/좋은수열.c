#include<stdio.h>
#include<stdbool.h>

int N, number[80]={0, };
bool found=false;

bool find_good(int index)
{
	for(int i=1;i<=index/2;i++)
	{
		bool same=true;

		for(int j=0;j<i;j++)
			if(number[index-j-1]!=number[index-i-j-1])
			{
				same=false;
				break;
			}

		if(same)
			return false;
	}

	return true;
}

void good_number(int index)
{
	if(found)
		return;
	if(index==1)
	{
		number[0]++;
		good_number(2);
	}
	else if(index==N+1)
	{
		if(find_good(index))
		{
			found=true;
			for(int i=0;i<N;i++)
				printf("%d", number[i]);
			printf("\n");
			return;
		}
		else
			find_good(index-1);
	}
	else
	{
		while(number[index-1]<3)
		{
			number[index-1]++;
			if(find_good(index))
			{
				good_number(index+1);
				break;
			}
		}
		if(!found)
		{
			number[index-1]=0;
			good_number(index-1);
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	good_number(1);
	return 0;
}