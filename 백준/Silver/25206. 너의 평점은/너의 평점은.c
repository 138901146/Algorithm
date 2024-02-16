#include<stdio.h>

int main(void)
{
	double total=0, credit, count=0;
	char subject[51], score[2];

	for(int i=0;i<20;++i)
	{
		scanf("%s%lf%s", subject, &credit, score);

		if(score[0]=='P')
			continue;

		count+=credit;

		if(score[0]=='F')
			continue;

		total+=credit*(69-score[0]+0.5*(score[1]=='+'));
	}

	printf("%lf", total/count);
	return 0;
}