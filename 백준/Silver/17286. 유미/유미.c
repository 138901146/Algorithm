#include<stdio.h>
#include<math.h>

int distance[4][4]={0};
double best=10000;

void simulate(double moved,int current,int visited)
{
	if(visited==15)
	{
		best=(int)moved<best?(int)moved:best;
		return;
	}

	for(int i=1;i<4;++i)
		if(!(1<<i&visited))
			simulate(moved+sqrt(distance[current][i]),i,1<<i|visited);
}

int main(void)
{
	int location[4][2];

	for(int i=0;i<4;++i)
	{
		scanf("%d%d", &location[i][0], &location[i][1]);

		for(int j=0;j<i;++j)
			distance[i][j]=distance[j][i]=(location[i][0]-location[j][0])*(location[i][0]-location[j][0])+(location[i][1]-location[j][1])*(location[i][1]-location[j][1]);
	}

	simulate(0,0,1);

	printf("%d", (int)best);
	return 0;
}