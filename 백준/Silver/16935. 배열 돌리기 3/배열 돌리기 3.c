#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, ***A=NULL, R, *order=NULL, bigger, current=0;

	scanf("%d%d%d", &N, &M, &R);
	bigger=N>M?N:M;
	A=(int ***)malloc(2*sizeof(int **));
	for(int i=0;i<2;i++)
	{
		A[i]=(int **)malloc(bigger*sizeof(int *));
		for(int j=0;j<bigger;j++)
			A[i][j]=(int *)malloc(bigger*sizeof(int));
	}
	order=(int *)malloc(R*sizeof(int));

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%d", &A[0][n][m]);
	for(int r=0;r<R;r++)
		scanf("%d", &order[r]);

	for(int r=0;r<R;r++)
		switch(order[r])
		{
			case 1:
			case 2:
				int one=0, two=0;
				while(r<R && order[r]>=1 && order[r]<=2)
				{
					if(order[r]==1)
						one++;
					else
						two++;
					r++;
				}
				r--;
				one%=2;
				two%=2;
				if(one==1)
				{
					int now=current%2, next=(current+1)%2;
					for(int n=0;n<N;n++)
						for(int m=0;m<M;m++)
							A[next][N-n-1][m]=A[now][n][m];
					current++;
				}
				if(two==1)
				{
					int now=current%2, next=(current+1)%2;
					for(int n=0;n<N;n++)
						for(int m=0;m<M;m++)
							A[next][n][m]=A[now][n][M-m-1];
					current++;
				}
				break;
			case 3:
			case 4:
				int right=0;

				while(r<R && order[r]>=3 && order[r]<=4)
				{
					if(order[r]==3)
						right++;
					else
						right--;
					r++;
				}
				r--;

				if(right<0)
				{
					while(right<-3)
						right+=4;
					while(right<0)
					{
						int now=current%2, next=(current+1)%2;
						right++;
						for(int m=0;m<M;m++)
							for(int n=0;n<N;n++)
								A[next][m][n]=A[now][n][M-m-1];
						current++;
						int temp=M;
						M=N;
						N=temp;
					}
				}
				else
				{
					right%=4;
					while(right>0)
					{
						int now=current%2, next=(current+1)%2;
						right--;
						for(int m=0;m<M;m++)
							for(int n=0;n<N;n++)
								A[next][m][n]=A[now][N-n-1][m];
						current++;
						int temp=M;
						M=N;
						N=temp;
					}
				}
				break;
			case 5:
			case 6:
				int clock=0;

				while(r<R && order[r]>=5 && order[r]<=6)
				{
					if(order[r]==5)
						clock++;
					else
						clock--;
					r++;
				}
				r--;

				while(clock<0)
					clock+=4;
				clock%=4;

				int now=current%2, next=(current+1)%2;
				switch(clock)
				{
					case 0:
						break;
					case 1:
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n][m]=A[now][n+N/2][m];
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n+N/2][m]=A[now][n+N/2][m+M/2];
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n+N/2][m+M/2]=A[now][n][m+M/2];
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n][m+M/2]=A[now][n][m];
						current++;
						break;
					case 2:
						for(int i=0;i<2;i++)
						{
							for(int n=0;n<N/2;n++)
								for(int m=0;m<M/2;m++)
									A[next][n+N/2][m]=A[now][n][m];
							for(int n=0;n<N/2;n++)
								for(int m=0;m<M/2;m++)
									A[next][n+N/2][m+M/2]=A[now][n+N/2][m];
							for(int n=0;n<N/2;n++)
								for(int m=0;m<M/2;m++)
									A[next][n][m+M/2]=A[now][n+N/2][m+M/2];
							for(int n=0;n<N/2;n++)
								for(int m=0;m<M/2;m++)
									A[next][n][m]=A[now][n][m+M/2];
							current++;
							now^=1;
							next^=1;
						}
						break;
					case 3:
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n+N/2][m]=A[now][n][m];
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n+N/2][m+M/2]=A[now][n+N/2][m];
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n][m+M/2]=A[now][n+N/2][m+M/2];
						for(int n=0;n<N/2;n++)
							for(int m=0;m<M/2;m++)
								A[next][n][m]=A[now][n][m+M/2];
						current++;
						break;
				}
				break;
		}

		current%=2;
		for(int n=0;n<N;n++)
		{
			for(int m=0;m<M;m++)
				printf("%d ", A[current][n][m]);
			printf("\n");
		}

		free(order);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<bigger;j++)
				free(A[i][j]);
			free(A[i]);
		}
		free(A);
		return 0;
}