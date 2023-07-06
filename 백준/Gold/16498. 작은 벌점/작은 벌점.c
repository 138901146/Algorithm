#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int count[3], **card=(int **)malloc(3*sizeof(int *)), diff=1000000000;

	for(int i=0;i<3;i++)
		scanf("%d", &count[i]);

	for(int i=0;i<3;i++)
	{
		card[i]=(int *)malloc(count[i]*sizeof(int));
		for(int j=0;j<count[i];j++)
			scanf("%d", &card[i][j]);
	}
	qsort((void *)card[2],(size_t)count[2],sizeof(int),compare);

	for(int i=0;i<count[0];i++)
		for(int j=0;j<count[1];j++)
		{
			int max=card[0][i]>card[1][j]?card[0][i]:card[1][j], min=max==card[0][i]?card[1][j]:card[0][i];

			for(int k=0;k<count[2];k++)
				if(card[2][k]<min)
					diff=max-card[2][k]<diff?max-card[2][k]:diff;
				else
				{
					if(card[2][k]>max)
						diff=card[2][k]-min<diff?card[2][k]-min:diff;
					else
						diff=max-min<diff?max-min:diff;
					break;
				}
		}

	printf("%d\n", diff);
	for(int i=0;i<3;i++)
		free(card[i]);
	free(card);
	return 0;
}