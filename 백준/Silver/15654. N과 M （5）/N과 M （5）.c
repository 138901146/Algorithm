#include<stdio.h>

int N, M, arr[8], selected[8];

void N_M(int current,int flag)
{
	if(current==M)
	{
		for(int i=0;i<M;++i)
			printf("%d ", arr[selected[i]]);
		printf("\n");
		return;
	}

	for(int i=0;i<N;++i)
		if(!(flag&(1<<i)))
		{
			selected[current]=i;
			N_M(current+1,1<<i|flag);
		}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &arr[i]);

		for(int j=0;j<i;++j)
			if(arr[i]<arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
	}

	N_M(0,0);

	return 0;
}