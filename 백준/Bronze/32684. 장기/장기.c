#include<stdio.h>

int main(void)
{
	int count, score[6]={13,7,5,3,3,2};
	float current[2]={0,1.5};

	for(int i=0;i<2;++i)
		for(int j=0;j<6;++j)
		{
			scanf("%d", &count);
			current[i]+=count*score[j];
		}

	printf("%s", current[0]<current[1]?"ekwoo":"cocjr0208");
	return 0;
}