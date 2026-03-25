#include<stdio.h>

int main(void)
{
	int H, M, start[8]={390,590,650,710,770,880,940,1000}, end[8]={540,600,660,720,830,890,950,1370};

	scanf("%d%d", &H, &M);

	M+=60*H;

	for(int i=0;i<8;++i)
		if(start[i]<=M&&M<=end[i])
		{
			printf("Yes");
			return 0;
		}

	printf("No");
	return 0;
}