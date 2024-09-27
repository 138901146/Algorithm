#include<stdio.h>

int main(void)
{
	int y, m, d, days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	scanf("%d%d%d", &d, &m, &y);

	while(y)
	{
		int count=0;

		for(int i=0;i<m;++i)
			count+=days[i];

		if(2<m)
			if(y%400==0 || (y%100!=0 && y%4==0))
				++count;

		printf("%d\n", count+d);
		scanf("%d%d%d", &d, &m, &y);
	}

	return 0;
}