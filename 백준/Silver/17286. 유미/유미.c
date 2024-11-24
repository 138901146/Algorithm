#include<stdio.h>
#include<math.h>

int x[4], y[4];
double min=10000;

void calculate(int current,int done,double distance)
{
	if(done==15)
	{
		min=distance<min?distance:min;
		return;
	}
	for(int i=1;i<4;++i)
		if(!(1<<i&done))
			calculate(i,1<<i|done,distance+sqrt((x[i]-x[current])*(x[i]-x[current])+(y[i]-y[current])*(y[i]-y[current])));
}

int main(void)
{
	for(int i=0;i<4;++i)
		scanf("%d%d", &x[i], &y[i]);

	calculate(0,1,0);

	printf("%d", (int)min);
	return 0;
}