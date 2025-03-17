#include<stdio.h>

int main(void)
{
	int T, K, N, student[100], record[1000][3];

	scanf("%d", &T);

	while(T--)
	{
		int best=-1, count=0;

		scanf("%d", &K);

		for(int k=0;k<K;++k)
			scanf("%d", &student[k]);

		scanf("%d", &N);

		for(int n=0;n<N;++n)
		{
			for(int i=0;i<3;++i)
				scanf("%d", &record[n][i]);

			for(int k=0;k<K;++k)
				if(student[k]==record[n][0])
				{
					if(record[n][1]<0)
						break;
					else if(best==-1)
						best=n;
					else if(record[n][1]<record[best][1] || record[n][1]==record[best][1]&&record[n][2]<record[best][2])
						best=n;

					if(record[n][1]<6 || record[n][1]==6&&record[n][2]==0)
						++count;

					break;
				}
		}

		printf("%d %d\n", record[best][0], count);
	}

	return 0;
}