#include<stdio.h>

int main(void)
{
	float score_num=0.0;
	char score[3]={'\0', };

	scanf("%s", score);

	if(score[0]!='F')
	{
		score_num+='E'-score[0];
		score_num+=0.3*(score[1]=='+');
		score_num-=0.3*(score[1]=='-');
	}

	printf("%.1f", score_num);
	return 0;
}