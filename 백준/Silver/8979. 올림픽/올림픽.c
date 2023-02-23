#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int number;
	int gold;
	int silver;
	int bronze;
	int rank;
}
country;

int main(void)
{
	int N, K;
	country *list=NULL;

	scanf("%d %d", &N, &K);
	list=(country *)malloc(N*sizeof(country));

	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d %d", &list[i].number, &list[i].gold, &list[i].silver, &list[i].bronze);
		list[i].rank=i+1;
	}

	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			if(list[i].gold<list[j].gold)
			{
				int temp=list[i].number;
				list[i].number=list[j].number;
				list[j].number=temp;
				temp=list[i].gold;
				list[i].gold=list[j].gold;
				list[j].gold=temp;
				temp=list[i].silver;
				list[i].silver=list[j].silver;
				list[j].silver=temp;
				temp=list[i].bronze;
				list[i].bronze=list[j].bronze;
				list[j].bronze=temp;
			}
			else if(list[i].gold==list[j].gold)
			{
				if(list[i].silver<list[j].silver)
				{
					int temp=list[i].number;
					list[i].number=list[j].number;
					list[j].number=temp;
					temp=list[i].gold;
					list[i].gold=list[j].gold;
					list[j].gold=temp;
					temp=list[i].silver;
					list[i].silver=list[j].silver;
					list[j].silver=temp;
					temp=list[i].bronze;
					list[i].bronze=list[j].bronze;
					list[j].bronze=temp;
				}
				else if(list[i].silver==list[j].silver)
				{
					if(list[i].bronze<list[j].bronze)
					{
						int temp=list[i].number;
						list[i].number=list[j].number;
						list[j].number=temp;
						temp=list[i].gold;
						list[i].gold=list[j].gold;
						list[j].gold=temp;
						temp=list[i].silver;
						list[i].silver=list[j].silver;
						list[j].silver=temp;
						temp=list[i].bronze;
						list[i].bronze=list[j].bronze;
						list[j].bronze=temp;
					}
				}
			}

	for(int i=0;i<N-1;i++)
		if(list[i].gold==list[i+1].gold && list[i].silver==list[i+1].silver && list[i].bronze==list[i+1].bronze)
			list[i+1].rank=list[i].rank;

	for(int i=0;i<N;i++)
		if(list[i].number==K)
		{
			printf("%d\n", list[i].rank);
			break;
		}
	free(list);
	return 0;
}