#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int K, location[6][2]={{0,0}, }, right=-500, left=500, up=-500, down=500, another[2], area=0;
	bool check[4]={false, };

	scanf("%d", &K);
	for(int i=0;i<5;i++)
	{
		int direction, distance;

		scanf("%d%d", &direction, &distance);

		if(direction==1)
		{
			location[i+1][0]=location[i][0]+distance;
			location[i+1][1]=location[i][1];
		}
		else if(direction==2)
		{
			location[i+1][0]=location[i][0]-distance;
			location[i+1][1]=location[i][1];
		}
		else if(direction==3)
		{
			location[i+1][0]=location[i][0];
			location[i+1][1]=location[i][1]-distance;
		}
		else
		{
			location[i+1][0]=location[i][0];
			location[i+1][1]=location[i][1]+distance;
		}
	}

	for(int i=0;i<6;i++)
	{
		if(location[i][0]<left)
			left=location[i][0];
		if(location[i][0]>right)
			right=location[i][0];
		if(location[i][1]<down)
			down=location[i][1];
		if(location[i][1]>up)
			up=location[i][1];
	}

	area=(up-down)*(right-left);

	for(int i=0;i<6;i++)
		if(location[i][0]==left && location[i][1]==down)
			check[0]=true;
		else if(location[i][0]==right && location[i][1]==down)
			check[1]=true;
		else if(location[i][0]==right && location[i][1]==up)
			check[2]=true;
		else if(location[i][0]==left && location[i][1]==up)
			check[3]=true;
		else if(location[i][0]!=left && location[i][0]!=right && location[i][1]!=down && location[i][1]!=up)
		{
			another[0]=location[i][0];
			another[1]=location[i][1];
		}

	if(!check[0])
		area-=(another[0]-left)*(another[1]-down);
	else if(!check[1])
		area-=(right-another[0])*(another[1]-down);
	else if(!check[2])
		area-=(right-another[0])*(up-another[1]);
	else
		area-=(another[0]-left)*(up-another[1]);

	printf("%d\n", K*area);
	return 0;
}