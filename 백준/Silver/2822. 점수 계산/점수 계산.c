#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int score[8], sorted[8], sum=0;

	for(int i=0;i<8;i++)
	{
		scanf("%d", &score[i]);
		sorted[i]=score[i];
	}

	qsort((void *)sorted,(size_t)8,sizeof(int),compare);

	for(int i=3;i<8;i++)
		sum+=sorted[i];

	printf("%d\n", sum);
	for(int i=0;i<8;i++)
		for(int j=3;j<8;j++)
			if(score[i]==sorted[j])
			{
				printf("%d ", i+1);
				break;
			}
	printf("\n");
	return 0;
}