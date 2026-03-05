#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, s, **sum=NULL;
	char **field=NULL;

	scanf("%d", &n);

	while(n--)
	{
		int max=0;

		scanf("%d", &s);

		field=(char **)malloc(s*sizeof(char *));
		sum=(int **)malloc((s+1)*sizeof(int *));

		sum[s]=(int *)calloc(s+1,sizeof(int));
		for(int i=0;i<s;++i)
		{
			field[i]=(char *)calloc(s+1,sizeof(char));
			sum[i]=(int *)calloc(s+1,sizeof(int));

			scanf("%s", field[i]);
		}

		for(int r=0;r<s;++r)
			for(int c=0;c<s;++c)
				sum[r+1][c+1]=(field[r][c]=='.')+sum[r+1][c]+sum[r][c+1]-sum[r][c];

		for(int r=1;r<=s;++r)
			for(int c=1;c<=s;++c)
			{
				int count=0;

				while(r+count<=s&&c+count<=s&&sum[r+count][c+count]-sum[r-1][c+count]-sum[r+count][c-1]+sum[r-1][c-1]==(count+1)*(count+1))
					++count;

				max=max<count?count:max;
			}

		printf("%d\n", max*max);
		for(int i=0;i<s;++i)
		{
			free(sum[i]);
			free(field[i]);
		}
		free(sum[s]);
		free(sum);
		free(field);
	}

	return 0;
}