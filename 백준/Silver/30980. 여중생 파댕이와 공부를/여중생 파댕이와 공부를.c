#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M;
	char **sheet=NULL;

	scanf("%d%d", &N, &M);
	sheet=(char **)malloc(3*N*sizeof(char *));

	for(int n=0;n<3*N;++n)
	{
		getchar();
		sheet[n]=(char *)calloc(M<<3|1,sizeof(char));
		scanf("%s", sheet[n]);
	}

	for(int n=1;n<3*N;n+=3)
		for(int m=0;m<(M<<3);m+=8)
		{
			int a=sheet[n][m+1]-'0', b=sheet[n][m+3]-'0', c=sheet[n][m+5]-'0';

			if(sheet[n][m+6]!='.')
			{
				c*=10;
				c+=sheet[n][m+6]-'0';
			}

			if(a+b==c)
			{
				for(int i=0;i<5+(c>9);++i)
					sheet[n-1][m+1+i]=sheet[n+1][m+1+i]='*';
				sheet[n][m]=sheet[n][m+6+(c>9)]='*';
			}
			else
				sheet[n-1][m+3]=sheet[n][m+2]=sheet[n+1][m+1]='/';
		}

	for(int n=0;n<3*N;++n)
	{
		printf("%s\n", sheet[n]);
		free(sheet[n]);
	}

	free(sheet);
	return 0;
}