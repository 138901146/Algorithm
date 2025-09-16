#include<stdio.h>
#include<stdbool.h>

bool range(int x,int low,int high)
{
	return low<=x&&x<=high;
}

int main(void)
{
	int distance;

	scanf("%d", &distance);

	distance%=100;

	if(range(distance,76,84))
		printf("4");
	else if(range(distance,41,49)||range(distance,71,75)||range(distance,85,89))
		printf("3");
	else if(range(distance,16,24)||range(distance,36,40)||range(distance,50,54)||range(distance,66,70)||range(distance,90,94))
		printf("2");
	else if(range(distance,0,0)||range(distance,10,10)||range(distance,30,30)||range(distance,60,60))
		printf("0");
	else
		printf("1");

	return 0;
}