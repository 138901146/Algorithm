#include<stdio.h>

int main(void)
{
	int time[2][3];

	for(int t=0;t<2;t++)
	{
		char str[9]={'\0', };

		scanf("%s", str);

		time[t][0]=10*(str[0]-'0')+str[1]-'0';
		time[t][1]=10*(str[3]-'0')+str[4]-'0';
		time[t][2]=10*(str[6]-'0')+str[7]-'0';
	}

	for(int t=0;t<3;t++)
		time[1][t]-=time[0][t];
	for(int t=2;t>0;t--)
		while(time[1][t]<0)
		{
			time[1][t-1]--;
			time[1][t]+=60;
		}
	while(time[1][0]<0)
		time[1][0]+=24;
	if(time[1][0]+time[1][1]+time[1][2]==0)
		time[1][0]=24;

	printf("%02d:%02d:%02d\n", time[1][0], time[1][1], time[1][2]);
	return 0;
}