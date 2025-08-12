#include<stdio.h>

#define INF 9876543210

int main(void)
{
	long long max_distance, carcenter_count, distance[102]={0}, fix_time[101]={0}, min[102]={0}, last[102]={0}, backtrace[102], visited_count=0, current;

	scanf("%lld", &max_distance);
	scanf("%lld", &carcenter_count);
	for(int i=1;i<carcenter_count+2;++i)
	{
		scanf("%lld", &distance[i]);
		distance[i]+=distance[i-1];
		min[i]=INF;
	}
	for(int i=1;i<=carcenter_count;++i)
		scanf("%lld", &fix_time[i]);

	if(distance[carcenter_count+1]<=max_distance)
	{
		printf("0\n0");
		return 0;
	}

	for(int i=1;i<carcenter_count+2;++i)
		for(int j=0;j<i;++j)
			if(distance[i]-distance[j]<=max_distance&&min[j]+fix_time[i]<min[i])
			{
				min[i]=min[j]+fix_time[i];
				last[i]=j;
			}

	current=last[carcenter_count+1];
	while(current)
	{
		backtrace[visited_count++]=current;
		current=last[current];
	}

	printf("%lld\n%lld\n", min[carcenter_count+1], visited_count);
	while(visited_count)
		printf("%lld ", backtrace[--visited_count]);
	return 0;
}