#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int kangaroo[3], count=0;

	for(int i=0;i<3;i++)
		scanf("%d", &kangaroo[i]);
	qsort((void *)kangaroo,(size_t)3,sizeof(int),compare);

	while(kangaroo[1]-kangaroo[0]>1 || kangaroo[2]-kangaroo[1]>1)
	{
		if(kangaroo[1]-kangaroo[0]>kangaroo[2]-kangaroo[1])
		{
			kangaroo[2]=kangaroo[1];
			kangaroo[1]--;
		}
		else
		{
			kangaroo[0]=kangaroo[1];
			kangaroo[1]++;
		}

		count++;
	}

	printf("%d\n", count);
	return 0;
}