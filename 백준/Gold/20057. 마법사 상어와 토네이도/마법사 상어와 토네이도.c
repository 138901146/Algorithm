#include<stdio.h>
#include<malloc.h>

int N, **A=NULL, lost=0;

void tornado(int sand,int r,int c,int target_r,int target_c)
{
	if(target_r<0 || target_c<0 || N<=target_r || N<=target_c)
		lost+=sand;
	else
		A[target_r][target_c]+=sand;
}

int main(void)
{
	int size=1, r, c;

	scanf("%d", &N);
	A=(int **)malloc(N*sizeof(int *));
	for(r=0;r<N;++r)
	{
		A[r]=(int *)malloc(N*sizeof(int));
		for(int c=0;c<N;++c)
			scanf("%d", &A[r][c]);
	}

	r=c=N>>1;
	for(int size=1;size<N;++size)
		if(size&1)
		{
			for(int i=0;i<size;++i)
			{
				int left=A[r][--c];

				if(A[r][c]/100)
				{
					tornado(A[r][c]/100,r,c,r-1,c+1);
					tornado(A[r][c]/100,r,c,r+1,c+1);
					left-=A[r][c]/100<<1;
				}
				if(7*A[r][c]/100)
				{
					tornado(7*A[r][c]/100,r,c,r-1,c);
					tornado(7*A[r][c]/100,r,c,r+1,c);
					left-=7*A[r][c]/100<<1;
				}
				if(A[r][c]/50)
				{
					tornado(A[r][c]/50,r,c,r-2,c);
					tornado(A[r][c]/50,r,c,r+2,c);
					left-=A[r][c]/50<<1;
				}
				if(A[r][c]/10)
				{
					tornado(A[r][c]/10,r,c,r-1,c-1);
					tornado(A[r][c]/10,r,c,r+1,c-1);
					left-=A[r][c]/10<<1;
				}
				if(A[r][c]/20)
				{
					tornado(A[r][c]/20,r,c,r,c-2);
					left-=A[r][c]/20;
				}

				if(0<c)
					A[r][c-1]+=left;
				else
					lost+=left;
				A[r][c]=0;
			}

			for(int i=0;i<size;++i)
			{
				int left=A[++r][c];

				if(A[r][c]/100)
				{
					tornado(A[r][c]/100,r,c,r-1,c-1);
					tornado(A[r][c]/100,r,c,r-1,c+1);
					left-=A[r][c]/100<<1;
				}
				if(7*A[r][c]/100)
				{
					tornado(7*A[r][c]/100,r,c,r,c-1);
					tornado(7*A[r][c]/100,r,c,r,c+1);
					left-=7*A[r][c]/100<<1;
				}
				if(A[r][c]/50)
				{
					tornado(A[r][c]/50,r,c,r,c-2);
					tornado(A[r][c]/50,r,c,r,c+2);
					left-=A[r][c]/50<<1;
				}
				if(A[r][c]/10)
				{
					tornado(A[r][c]/10,r,c,r+1,c-1);
					tornado(A[r][c]/10,r,c,r+1,c+1);
					left-=A[r][c]/10<<1;
				}
				if(A[r][c]/20)
				{
					tornado(A[r][c]/20,r,c,r+2,c);
					left-=A[r][c]/20;
				}

				if(r<N-1)
					A[r+1][c]+=left;
				else
					lost+=left;
				A[r][c]=0;
			}
		}
		else
		{
			for(int i=0;i<size;++i)
			{
				int left=A[r][++c];

				if(A[r][c]/100)
				{
					tornado(A[r][c]/100,r,c,r-1,c-1);
					tornado(A[r][c]/100,r,c,r+1,c-1);
					left-=A[r][c]/100<<1;
				}
				if(7*A[r][c]/100)
				{
					tornado(7*A[r][c]/100,r,c,r-1,c);
					tornado(7*A[r][c]/100,r,c,r+1,c);
					left-=7*A[r][c]/100<<1;
				}
				if(A[r][c]/50)
				{
					tornado(A[r][c]/50,r,c,r-2,c);
					tornado(A[r][c]/50,r,c,r+2,c);
					left-=A[r][c]/50<<1;
				}
				if(A[r][c]/10)
				{
					tornado(A[r][c]/10,r,c,r-1,c+1);
					tornado(A[r][c]/10,r,c,r+1,c+1);
					left-=A[r][c]/10<<1;
				}
				if(A[r][c]/20)
				{
					tornado(A[r][c]/20,r,c,r,c+2);
					left-=A[r][c]/20;
				}

				if(c<N-1)
					A[r][c+1]+=left;
				else
					lost+=left;
				A[r][c]=0;
			}

			for(int i=0;i<size;++i)
			{
				int left=A[--r][c];

				if(A[r][c]/100)
				{
					tornado(A[r][c]/100,r,c,r+1,c-1);
					tornado(A[r][c]/100,r,c,r+1,c+1);
					left-=A[r][c]/100<<1;
				}
				if(7*A[r][c]/100)
				{
					tornado(7*A[r][c]/100,r,c,r,c-1);
					tornado(7*A[r][c]/100,r,c,r,c+1);
					left-=7*A[r][c]/100<<1;
				}
				if(A[r][c]/50)
				{
					tornado(A[r][c]/50,r,c,r,c-2);
					tornado(A[r][c]/50,r,c,r,c+2);
					left-=A[r][c]/50<<1;
				}
				if(A[r][c]/10)
				{
					tornado(A[r][c]/10,r,c,r-1,c-1);
					tornado(A[r][c]/10,r,c,r-1,c+1);
					left-=A[r][c]/10<<1;
				}
				if(A[r][c]/20)
				{
					tornado(A[r][c]/20,r,c,r-2,c);
					left-=A[r][c]/20;
				}

				if(0<r)
					A[r-1][c]+=left;
				else
					lost+=left;
				A[r][c]=0;
			}
		}

		for(int i=1;i<N;++i)
		{
			int left=A[r][--c];

			if(A[r][c]/100)
			{
				tornado(A[r][c]/100,r,c,r-1,c+1);
				tornado(A[r][c]/100,r,c,r+1,c+1);
				left-=A[r][c]/100<<1;
			}
			if(7*A[r][c]/100)
			{
				tornado(7*A[r][c]/100,r,c,r-1,c);
				tornado(7*A[r][c]/100,r,c,r+1,c);
				left-=7*A[r][c]/100<<1;
			}
			if(A[r][c]/50)
			{
				tornado(A[r][c]/50,r,c,r-2,c);
				tornado(A[r][c]/50,r,c,r+2,c);
				left-=A[r][c]/50<<1;
			}
			if(A[r][c]/10)
			{
				tornado(A[r][c]/10,r,c,r-1,c-1);
				tornado(A[r][c]/10,r,c,r+1,c-1);
				left-=A[r][c]/10<<1;
			}
			if(A[r][c]/20)
			{
				tornado(A[r][c]/20,r,c,r,c-2);
				left-=A[r][c]/20;
			}

			if(0<c)
				A[r][c-1]+=left;
			else
				lost+=left;
			A[r][c]=0;
		}

	printf("%d", lost);
	for(int n=0;n<N;++n)
		free(A[n]);
	free(A);
	return 0;
}