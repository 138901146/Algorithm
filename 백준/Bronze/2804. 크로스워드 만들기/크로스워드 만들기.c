#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	char A[31]={'\0'}, B[31]={'\0'}, result[31][31]={'\0'};
	int M, N, n, m;
	bool flag=false;

	scanf("%s%s", A, B);
	M=strlen(A);
	N=strlen(B);

	for(m=0;m<M && !flag;++m)
		for(n=0;n<N;++n)
			if(A[m]==B[n])
			{
				flag=true;
				break;
			}
	--m;

	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			result[i][j]='.';

	for(int i=0;i<M;++i)
		result[i][n]=A[i];
	for(int i=0;i<N;++i)
		result[m][i]=B[i];

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
			printf("%c", result[j][i]);
		printf("\n");
	}

	return 0;
}