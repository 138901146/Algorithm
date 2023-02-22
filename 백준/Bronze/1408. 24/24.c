#include<stdio.h>

int main(void)
{
	int time[2][3];

	for(int i=0;i<2;i++)
		scanf("%2d:%2d:%2d", &time[i][0], &time[i][1], &time[i][2]);

	for(int i=0;i<3;i++)
		time[1][i]-=time[0][i];

	for(int i=2;i>0;i--)
		while(time[1][i]<0)
		{
			time[1][i]+=60;
			time[1][i-1]--;
		}
	while(time[1][0]<0)
		time[1][0]+=24;

	printf("%02d:%02d:%02d\n", time[1][0], time[1][1], time[1][2]);

	return 0;
}