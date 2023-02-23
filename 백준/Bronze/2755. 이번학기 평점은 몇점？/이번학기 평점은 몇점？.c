#include<stdio.h>

int main(void)
{
	int N, sum=0;
	float total=0.0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		char name[101]={'\0', }, score[3]={'\0', };
		int times;
		float subject_score=0.0;

		scanf("%s %d %s", name, &times, score);

		if(score[0]!='F')
		{
			subject_score+='E'-score[0];
			subject_score+=0.3*(score[1]=='+');
			subject_score-=0.3*(score[1]=='-');
		}

		sum+=times;
		total+=subject_score*times;
	}

	total/=sum;
	total*=1000;
	total+=(int)total%10>4;
	total/=1000;

	printf("%.2f\n", total);
	return 0;
}