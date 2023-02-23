#include<stdio.h>

int main(void)
{
	int level[4];

	for(int l=0;l<4;l++)
		scanf("%d", &level[l]);

	for(int i=0;i<3;i++)
		for(int j=i+1;j<4;j++)
			if(level[i]>level[j])
			{
				int temp=level[i];
				level[i]=level[j];
				level[j]=temp;
			}
	level[0]+=level[3];
	level[1]+=level[2];

	printf("%d\n", level[0]>level[1]?level[0]-level[1]:level[1]-level[0]);
	return 0;
}