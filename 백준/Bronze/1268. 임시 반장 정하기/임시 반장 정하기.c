#include<stdio.h>
#include<stdbool.h>

bool meet[1000][1000]={false};

int main(void)
{
	int N, same[1000]={0}, class, student[5][10][1000], count[5][10]={0}, president=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		for(int grade=0;grade<5;++grade)
		{
			scanf("%d", &class);
			student[grade][class][count[grade][class]++]=n;
		}

	for(int grade=0;grade<5;++grade)
		for(int class=1;class<10;++class)
			for(int i=0;i<count[grade][class];++i)
				for(int j=i+1;j<count[grade][class];++j)
					meet[student[grade][class][i]][student[grade][class][j]]=meet[student[grade][class][j]][student[grade][class][i]]=true;

	for(int n=0;n<N;++n)
	{
		for(int i=0;i<N;++i)
			same[n]+=meet[n][i];
		president=same[n]>same[president]?n:president;
	}

	printf("%d", president+1);
	return 0;
}