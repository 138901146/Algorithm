#include<stdio.h>

int main(void)
{
	int num[3];

	for(int i=0;i<3;++i)
		scanf("%d", &num[i]);

	for(int i=0;i<3;++i)
		for(int j=i+1;j<3;++j)
			if(num[j]<num[i])
			{
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}

	printf("%d", num[0]+num[1]==num[2]?1:num[0]*num[1]==num[2]?2:3);
	return 0;
}