#include<stdio.h>
int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int x1, y1, r1, x2, y2, r2, d;
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

		d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

		if((r1+r2)*(r1+r2)<d)			//멀어서 만나지 않는 경우
			printf("0\n");
		else if(d==0 && r1==r2)			//일치하는 경우
			printf("-1\n");
		else if((r1+r2)*(r1+r2)==d)			//외접하는 경우
			printf("1\n");
		else if(d==0 && r1!=r2)			//중심이 같고 반지름이 달라 만나지 않는 경우
			printf("0\n");
		else if((r1-r2)*(r1-r2)==d)			//내접하는 경우
			printf("1\n");
		else if((r1-r2)*(r1-r2)<d && d<(r1+r2)*(r1+r2))	//두 점에서 만나는 경우
			printf("2\n");
		else
			printf("0\n");
	}

	return 0;
}