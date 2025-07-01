#include<stdio.h>

#define INF 1000000

int abs(int x)
{
	return x<0?-x:x;
}

int get_power(int x,int y)
{
	if(!x||!y)
		return 2;
	else if(x==y)
		return 1;
	else if(abs(x-y)==2)
		return 4;
	else
		return 3;
}

int main(void)
{
	int power[5][5][2], previous=0, current=1, command, min=INF;

	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			power[i][j][0]=INF;
	power[0][0][0]=0;

	scanf("%d", &command);
	while(command)
	{
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				power[i][j][current]=INF;

		for(int i=0;i<5;++i)
		{
			if(i==command)
				continue;

			for(int j=0;j<5;++j)
			{
				if(power[j][i][previous]+get_power(command,j)<power[command][i][current])
					power[command][i][current]=power[j][i][previous]+get_power(command,j);
				if(power[i][j][previous]+get_power(command,j)<power[i][command][current])
					power[i][command][current]=power[i][j][previous]+get_power(command,j);
			}
		}

		current^=1;
		previous^=1;
		scanf("%d", &command);
	}

	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			min=power[i][j][previous]<min?power[i][j][previous]:min;

	printf("%d", min);
	return 0;
}