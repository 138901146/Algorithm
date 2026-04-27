#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?-1:1;
}

int main(void)
{
	int N, level[100], sum=0, max, up=0;

	scanf("%d", &N);
	max=N>42?42:N;

	for(int n=0;n<N;n++)
		scanf("%d", &level[n]);

	qsort((void *)level,(size_t)N,sizeof(int),compare);

	for(int i=0;i<max;i++)
	{
		sum+=level[i];
		if(level[i]>249)
			up+=5;
		else if(level[i]>199)
			up+=4;
		else if(level[i]>139)
			up+=3;
		else if(level[i]>99)
			up+=2;
		else if(level[i]>59)
			up++;
	}

	printf("%d %d\n", sum, up);
	return 0;
}