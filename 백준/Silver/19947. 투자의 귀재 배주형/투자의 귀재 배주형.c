#include<stdio.h>

int main(void)
{
	int H, Y;

	scanf("%d %d", &H, &Y);

	switch(Y)
	{
		case 1:
		case 2:
		case 3:
		case 6:
		case 9:
				for(int A=0;A<Y%3;A++)
					H*=1.05;
				for(int B=3;B<=Y;B+=3)
					H*=1.2;
				break;
		case 5:
		case 10:
				for(int C=5;C<=Y;C+=5)
					H*=1.35;
				for(int B=0;B<Y%5;B+=3)
					H*=1.2;
				break;
		case 4:
		{
				int compare[2];

				compare[0]=compare[1]=H;
				for(int i=0;i<2;i++)
					for(int j=0;j<2;j++)
						compare[j]*=i==j?1.05:1.2;
				H=compare[0]>compare[1]?compare[0]:compare[1];
				break;
		}
		case 7:
		{
				int compare[3];

				compare[0]=compare[1]=compare[2]=H;
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						compare[j]*=i==j?1.05:1.2;
				for(int i=0;i<3;i++)
					H=compare[i]>H?compare[i]:H;
				break;
		}
		case 8:
		{
				int compare[2];

				compare[0]=compare[1]=H;
				for(int i=0;i<2;i++)
					for(int j=0;j<2;j++)
						compare[j]*=i==j?1.35:1.2;
				H=compare[0]<compare[1]?compare[1]:compare[0];
				break;
		}
		default:
				break;
	}

	printf("%d\n", H);

	return 0;
}