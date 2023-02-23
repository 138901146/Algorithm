#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	for(int t=0;t<4;t++)
	{
		int rectangle[2][4][2], x, y, p, q;
		bool is_b=false, is_c=false, is_d=false;

		for(int i=0;i<2;i++)
		{
			scanf("%d%d%d%d", &x, &y, &p, &q);
			rectangle[i][0][0]=rectangle[i][3][0]=x;
			rectangle[i][0][1]=rectangle[i][1][1]=y;
			rectangle[i][1][0]=rectangle[i][2][0]=p;
			rectangle[i][2][1]=rectangle[i][3][1]=q;
		}

		for(int i=0;i<4;i++)
			if(rectangle[0][i][0]==rectangle[1][(i+2)%4][0] && rectangle[0][i][1]==rectangle[1][(i+2)%4][1])
			{
				is_c=true;
				break;
			}

		if(is_c)
		{
			printf("c\n");
			continue;
		}
		
		for(int i=0;i<2;i++)
			if(rectangle[i][0][0]>rectangle[(i+1)%2][1][0] || rectangle[i][0][1]>rectangle[(i+1)%2][2][1])
			{
				is_d=true;
				break;
			}
			else if(rectangle[i][0][0]==rectangle[(i+1)%2][1][0] || rectangle[i][0][1]==rectangle[(i+1)%2][2][1])
			{
				is_b=true;
				break;
			}
		if(is_d)
		{
			printf("d\n");
			continue;
		}
		if(is_b)
		{
			printf("b\n");
			continue;
		}
		printf("a\n");
	}

	return 0;
}