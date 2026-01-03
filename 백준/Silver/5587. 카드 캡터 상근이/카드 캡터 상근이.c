#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int n, sg[100], gs[100], count[2]={0}, turn=0, sg_idx=0, gs_idx=0, last=0;
	bool appeared[201]={false}, used[100][2]={false};

	scanf("%d", &n);
	for(int i=0;i<n;++i)
	{
		scanf("%d", &sg[i]);
		appeared[sg[i]]=true;
	}
	for(int i=1;i<=2*n;++i)
		if(!appeared[i])
			gs[count[1]++]=i;

	qsort((void *)sg,(size_t)n,sizeof(int),compare);

	count[1]=0;
	while(count[0]!=n&&count[1]!=n)
	{
		if(turn==0)
		{
			while(sg_idx<n&&(sg[sg_idx]<last||used[sg_idx][turn]))
				++sg_idx;
			if(sg_idx==n)
			{
				sg_idx=gs_idx=last=0;
				turn^=1;
				continue;
			}
			last=sg[sg_idx];
			used[sg_idx][turn]=true;
		}
		else
		{
			while(gs_idx<n&&(gs[gs_idx]<last||used[gs_idx][turn]))
				++gs_idx;
			if(gs_idx==n)
			{
				sg_idx=gs_idx=last=0;
				turn^=1;
				continue;
			}
			last=gs[gs_idx];
			used[gs_idx][turn]=true;
		}

		++count[turn];
		turn^=1;
	}

	printf("%d\n%d", n-count[1], n-count[0]);
	return 0;
}