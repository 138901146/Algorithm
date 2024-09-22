#include<stdio.h>

int main(void)
{
	int N, M, a[30][30], max=0;

	scanf("%d%d", &N, &M);

	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", &a[i][j]);

	for(int i=0;i<M;++i)
		for(int j=i+1;j<M;++j)
			for(int k=j+1;k<M;++k)
			{
				int sum=0;

				for(int l=0;l<N;++l)
				{
					int satisfy=a[l][i];

					if(satisfy<a[l][j])
						satisfy=a[l][j];
					if(satisfy<a[l][k])
						satisfy=a[l][k];

					sum+=satisfy;
				}

				max=sum<max?max:sum;
			}

	printf("%d", max);
	return 0;
}