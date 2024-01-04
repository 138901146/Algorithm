#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int r, c, count=0;
		char **candy=NULL;

		scanf("%d%d", &r, &c);
		candy=(char **)malloc(r*sizeof(char *));
		
		for(int i=0;i<r;++i)
		{
			getchar();
			candy[i]=(char *)calloc(c+1,sizeof(char));
			scanf("%s", candy[i]);
		}

		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				if(candy[i][j]==111)
				{
					if(i>0 && i<r-1 && candy[i-1][j]==118 && candy[i+1][j]==94)
						++count;
					if(j>0 && j<c-1 && candy[i][j-1]==62 && candy[i][j+1]==60)
						++count;
				}

		printf("%d\n", count);
		while(r--)
			free(candy[r]);
		free(candy);
	}

	return 0;
}