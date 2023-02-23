#include<stdio.h>

int main(void)
{
	int N, pillar[1001]={0, }, *left=NULL, *right=NULL, L, H, left_current=1, right_current=1, area=0;

	scanf("%d", &N);
	left=(int *)calloc(N+1,sizeof(int));
	right=(int *)calloc(N+1,sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d%d", &L, &H);
		pillar[L]=H;
	}

	left[0]=0;
	for(int n=0;n<1001;n++)
		if(pillar[n]>pillar[left[left_current-1]])
			left[left_current++]=n;

	right[0]=1000;
	for(int n=1000;n>=0;n--)
		if(pillar[n]>pillar[right[right_current-1]])
			right[right_current++]=n;

	for(int i=1;i<left_current;i++)
		area+=(left[i]-left[i-1])*pillar[left[i-1]];
	for(int i=1;i<right_current;i++)
		area+=(right[i-1]-right[i])*pillar[right[i-1]];
	area+=(right[right_current-1]-left[left_current-1]+1)*pillar[left[left_current-1]];

	printf("%d\n", area);
	free(right);
	free(left);
	return 0;
}