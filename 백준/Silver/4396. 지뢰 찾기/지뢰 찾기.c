#include<stdio.h>

int main(void)
{
	int n, bomb=0, dr[8]={-1,-1,0,1,1,1,0,-1}, dc[8]={0,1,1,1,0,-1,-1,-1};
	char status[10][11]={0}, current[10][11]={0};

	scanf("%d", &n);

	for(int i=0;i<n;++i)
		scanf("%s", status[i]);
	for(int i=0;i<n;++i)
		scanf("%s", current[i]);

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(status[i][j]=='*'&&current[i][j]=='x')
				bomb=1;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)

			if(bomb&&status[i][j]=='*')
				printf("*");
			else if(current[i][j]=='.')
				printf(".");
			else
			{
				int count=0;

				for(int k=0;k<8;++k)
				{
					int r=i+dr[k], c=j+dc[k];

					if(r<0||n<=r||c<0||n<=c)
						continue;

					count+=status[r][c]=='*';
				}

				printf("%d", count);
			}
		printf("\n");
	}

	return 0;
}