#include<stdio.h>

int main(void)
{
	int time[2][3], ride=0;

	for(int i=0;i<2;i++)
		scanf("%d : %d : %d", &time[i][0], &time[i][1], &time[i][2]);

	for(int t=2;t>0;t--)
		if(time[0][t]>time[1][t])
		{
			time[1][t]+=60;
			time[1][t-1]--;
		}
	if(time[0][0]>time[1][0])
		time[1][0]+=24;

	for(int i=2,gap=1;i>=0;i--,gap*=60)
		ride+=gap*(time[1][i]-time[0][i]);

	printf("%d\n", ride);
	return 0;
}