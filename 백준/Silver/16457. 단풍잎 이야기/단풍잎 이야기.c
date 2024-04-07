#include<stdio.h>
#include<malloc.h>

int n, m, k, **required=NULL, max=0;

void quest(int skill)
{
	int count=0;

	for(int i=0;i<m;++i)
	{
		int flag=1;

		for(int j=0;j<k && flag;++j)
			if(!(skill&(1<<required[i][j])))
				flag=0;

		count+=flag;
	}

	max=max<count?count:max;
}

void combination(int last,int assigned,int skill)
{
	if(assigned==n)
	{
		quest(skill);
		return;
	}

	for(int i=last+1;i<=(n<<1);++i)
		combination(i,assigned+1,1<<i|skill);
}

int main(void)
{
	scanf("%d%d%d", &n, &m, &k);
	required=(int **)malloc(m*sizeof(int *));

	for(int i=0;i<m;++i)
	{
		required[i]=(int *)malloc(k*sizeof(int));
		for(int j=0;j<k;++j)
			scanf("%d", &required[i][j]);
	}

	combination(0,0,0);

	printf("%d", max);
	for(int i=0;i<m;++i)
		free(required[i]);
	free(required);
	return 0;
}