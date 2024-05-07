#include<stdio.h>

int matrix[3][3], origin[3][3], count=0, check[8][3][2]={{{0,0},{0,1},{0,2}},{{1,0},{1,1},{1,2}},{{2,0},{2,1},{2,2}},{{0,0},{1,0},{2,0}},{{0,1},{1,1},{2,1}},{{0,2},{1,2},{2,2}},{{0,0},{1,1},{2,2}},{{0,2},{1,1},{2,0}}}, min=99;

int abs(int x)
{
	return x<0?-x:x;
}

void simulate(int flag,int r,int c)
{
	if(r==3)
	{
		int base=matrix[0][0]+matrix[0][1]+matrix[0][2], diff=0;

		for(int i=1;i<8;++i)
		{
			int sum=0;

			for(int j=0;j<3;++j)
				sum+=matrix[check[i][j][0]][check[i][j][1]];

			if(sum!=base)
				return;
		}

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				diff+=abs(matrix[i][j]-origin[i][j]);

		min=diff<min?diff:min;
		return;
	}

	for(int i=0;i<9;++i)
		if(!(flag&(1<<i)))
		{
			matrix[r][c]=i+1;
			if(c==2)
				simulate(1<<i|flag,r+1,0);
			else
				simulate(1<<i|flag,r,c+1);
		}
}

int main(void)
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			scanf("%d", &origin[i][j]);

	simulate(0,0,0);

	printf("%d", min);
	return 0;
}