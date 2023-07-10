#include<stdio.h>

int N, M, office[8][8], CCTV[8], CCTV_count=0, min=64, operation[32];

void find_min(int index,int operation_count)
{
	if(index==CCTV_count)
	{
		int count=0;
		for(int i=0;i<operation_count;i++)
		{
			int x=operation[i]&7, y=(operation[i]>>3)&7, move=operation[i]>>6;

			switch(move)
			{
				case 0:
					while(y>=0)
					{
						if(office[y][x]==0)
							office[y][x]=-1;
						else if(office[y][x]==6)
							break;
						y--;
					}
					break;
				case 1:
					while(x>=0)
					{
						if(office[y][x]==0)
							office[y][x]=-1;
						else if(office[y][x]==6)
							break;
						x--;
					}
					break;
				case 2:
					while(y<N)
					{
						if(office[y][x]==0)
							office[y][x]=-1;
						else if(office[y][x]==6)
							break;
						y++;
					}
					break;
				case 3:
					while(x<M)
					{
						if(office[y][x]==0)
							office[y][x]=-1;
						else if(office[y][x]==6)
							break;
						x++;
					}
					break;
			}
		}

		for(int n=0;n<N;n++)
			for(int m=0;m<M;m++)
				if(office[n][m]==0)
					count++;
				else if(office[n][m]==-1)
					office[n][m]=0;

		min=count<min?count:min;
		return;
	}

	int x=CCTV[index]&7, y=(CCTV[index]>>3)&7, type=CCTV[index]>>6;

	switch(type)
	{
		case 1:
			for(int i=0;i<4;i++)
			{
				operation[operation_count]=i<<6|y<<3|x;
				find_min(index+1,operation_count+1);
			}
			break;
		case 2:
			for(int i=0;i<2;i++)
			{
				operation[operation_count]=i<<6|y<<3|x;
				operation[operation_count+1]=(2|i)<<6|y<<3|x;
				find_min(index+1,operation_count+2);
			}
			break;
		case 3:
			for(int i=0;i<4;i++)
			{
				operation[operation_count]=i<<6|y<<3|x;
				operation[operation_count+1]=((i+1)&3)<<6|y<<3|x;
				find_min(index+1,operation_count+2);
			}
			break;
		case 4:
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
					if(i!=j)
						operation[operation_count++]=j<<6|y<<3|x;
				find_min(index+1,operation_count);
				operation_count-=3;
			}
			break;
		case 5:
			for(int i=0;i<4;i++)
				operation[operation_count+i]=i<<6|y<<3|x;
			find_min(index+1,operation_count+4);
			break;
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
		{
			scanf("%d", &office[n][m]);
			if(office[n][m]>0 && office[n][m]<6)
				CCTV[CCTV_count++]=office[n][m]<<6|n<<3|m;
		}

	find_min(0,0);

	printf("%d\n", min);
	return 0;
}