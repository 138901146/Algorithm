#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int index, value;
}
skill;

int compare(const void *x,const void *y)
{
	return ((skill *)x)->value>((skill *)y)->value?-1:1;
}

skill best[5][5];
int index[5], max=0;

void find_best(int current)
{
	if(current==5)
	{
		int sum=0;

		for(int i=0;i<5;i++)
			sum+=best[i][index[i]].value;
		max=sum>max?sum:max;

		return;
	}

	int check[5];

	for(int i=0;i<current;i++)
		check[i]=best[i][index[i]].index;

	for(int i=0;i<5;i++)
	{
		bool same=false;

		for(int j=0;j<current;j++)
			if(check[j]==best[current][i].index)
			{
				same=true;
				break;
			}

		if(!same)
		{
			index[current]=i;
			find_best(current+1);
		}
	}
}

int main(void)
{
	int n;
	skill **player=(skill **)malloc(5*sizeof(skill *));

	scanf("%d", &n);
	for(int i=0;i<5;i++)
		player[i]=(skill *)malloc(n*sizeof(skill));

	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
		{
			scanf("%d", &player[j][i].value);
			player[j][i].index=i;
		}

	for(int i=0;i<5;i++)
	{
		qsort((void *)player[i],(size_t)n,sizeof(skill),compare);
		for(int j=0;j<5;j++)
			best[i][j]=player[i][j];
		free(player[i]);
	}
	free(player);

	find_best(0);
	printf("%d\n", max);
	return 0;
}