#include<stdio.h>

int main(void)
{
	int length[3];

	for(int l=0;l<3;l++)
		scanf("%d", &length[l]);

	for(int i=0;i<2;i++)
		for(int j=i+1;j<3;j++)
			if(length[i]>length[j])
			{
				int temp=length[i];
				length[i]=length[j];
				length[j]=temp;
			}

	printf("%d\n", length[0]+length[1]>length[2]?length[0]+length[1]+length[2]:2*(length[0]+length[1])-1);
	return 0;
}