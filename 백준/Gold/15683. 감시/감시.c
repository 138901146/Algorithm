#include<stdio.h>
#include<stdlib.h>

int N, M, CCTV_count=0, *CCTV=NULL, **office=NULL;

int blind_spot(int current)
{
	if(current==CCTV_count)
	{
		int area=0, wall_count=0;

		for(int i=0;i<CCTV_count;i++)
		{
			int x=CCTV[i]/10, y=CCTV[i]%10;

			if((office[x][y]&(1<<3))!=0)
			{
				while(x>0 && office[x-1][y]!=6)
				{
					x--;
					if(office[x][y]==0)
						office[x][y]=-1;
				}
				x=CCTV[i]/10;
				y=CCTV[i]%10;
			}
			if((office[x][y]&(1<<4))!=0)
			{
				while(x<N-1 && office[x+1][y]!=6)
				{
					x++;
					if(office[x][y]==0)
						office[x][y]=-1;
				}
				x=CCTV[i]/10;
				y=CCTV[i]%10;
			}
			if((office[x][y]&(1<<5))!=0)
			{
				while(y>0 && office[x][y-1]!=6)
				{
					y--;
					if(office[x][y]==0)
						office[x][y]=-1;
				}
				x=CCTV[i]/10;
				y=CCTV[i]%10;
			}
			if((office[x][y]&(1<<6))!=0)
			{
				while(y<M-1 && office[x][y+1]!=6)
				{
					y++;
					if(office[x][y]==0)
						office[x][y]=-1;
				}
				x=CCTV[i]/10;
				y=CCTV[i]%10;
			}
		}

		for(int n=0;n<N;n++)
			for(int m=0;m<M;m++)
				if(office[n][m]==-1)
					office[n][m]=0;
				else if(office[n][m]==0)
					area++;

		return area;
	}

	int x=CCTV[current]/10, y=CCTV[current]%10, min=64, temp;

	switch(office[x][y])
	{
		case 1:
			office[x][y]|=1<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=1<<3;
			office[x][y]|=1<<4;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=1<<4;
			office[x][y]|=1<<5;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=1<<5;
			office[x][y]|=1<<6;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=1<<6;
			break;
		case 2:
			office[x][y]|=3<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=3<<3;
			office[x][y]|=3<<5;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=3<<5;
			break;
		case 3:
			office[x][y]|=5<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=5<<3;
			office[x][y]|=9<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=9<<3;
			office[x][y]|=3<<4;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=3<<4;
			office[x][y]|=5<<4;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=5<<4;
			break;
		case 4:
			office[x][y]|=14<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=14<<3;
			office[x][y]|=13<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=13<<3;
			office[x][y]|=11<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=11<<3;
			office[x][y]|=7<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=7<<3;
			break;
		case 5:
			office[x][y]|=15<<3;
			temp=blind_spot(current+1);
			if(temp<min)
				min=temp;
			office[x][y]^=15<<3;
			break;
		default:
			break;
	}

	return min;
}

int main(void)
{
	scanf("%d%d", &N, &M);
	office=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
	{
		office[n]=(int *)malloc(M*sizeof(int));

		for(int m=0;m<M;m++)
		{
			scanf("%d", &office[n][m]);
			if(office[n][m]>0 && office[n][m]<6)
				CCTV_count++;
		}
	}

	CCTV=(int *)malloc(CCTV_count*sizeof(int));
	CCTV_count=0;

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			if(office[n][m]>0 && office[n][m]<6)
				CCTV[CCTV_count++]=10*n+m;

	printf("%d\n", blind_spot(0));
	free(CCTV);
	for(int n=0;n<N;n++)
		free(office[n]);
	free(office);
	return 0;
}