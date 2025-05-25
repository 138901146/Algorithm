#include<stdio.h>

int main(void)
{
	int L, a[6]={0}, g[7]={0}, limit_a[8]={200,210,220,225,230,235,245,250}, limit_g=260;

	scanf("%d", &L);

	for(int i=0;i<6;++i)
		if(limit_a[i+2]<=L)
			a[i]=100;
		else if(limit_a[i+1]<=L)
			a[i]=300;
		else if(limit_a[i]<=L)
			a[i]=500;

	for(int i=0;i<7;++i,limit_g+=5)
		if(limit_g+10<=L)
			g[i]=100;
		else if(limit_g+5<=L)
			g[i]=300;
		else if(limit_g<=L)
			g[i]=500;

	for(int i=0;i<6;++i)
		printf("%d ", a[i]);
	printf("\n");
	for(int i=0;i<7;++i)
		printf("%d ", g[i]);
	return 0;
}