#include<stdio.h>

int main(void)
{
	int N, M, picture[101][101]={0}, x_s, y_s, x_e, y_e, count=0;

	scanf("%d%d", &N, &M);

	while(N--)
	{
		scanf("%d%d%d%d", &x_s, &y_s, &x_e, &y_e);
		for(int x=x_s;x<=x_e;++x)
			for(int y=y_s;y<=y_e;++y)
				count+=++picture[x][y]==M+1;
	}

	printf("%d", count);
	return 0;
}