#include<stdio.h>

int arr[10], A[9], k, min_arr[10], max_arr[10];
long long min=999999999999999, max=0;

void inequality(int index)
{
	if(index==k+1)
	{
		long long ans=0;

		for(int i=0;i<index;i++)
		{
			ans*=10;
			ans+=arr[i];
		}

		if(ans<min)
		{
			for(int i=0;i<index;i++)
				min_arr[i]=arr[i];
			min=ans;
		}
		if(ans>max)
		{
			for(int i=0;i<index;i++)
				max_arr[i]=arr[i];
			max=ans;
		}
		return;
	}

	int check[10]={0, };

	for(int i=0;i<index;i++)
		check[arr[i]]=1;

	for(int i=0;i<10;i++)
		if(index==0)
		{
			arr[0]=i;
			inequality(1);
		}
		else if(check[i])
			continue;
		else if(A[index-1]==0 && arr[index-1]>i)
		{
			arr[index]=i;
			inequality(index+1);
		}
		else if(A[index-1]==1 && arr[index-1]<i)
		{
			arr[index]=i;
			inequality(index+1);
		}
}

int main(void)
{
	char c;

	scanf("%d", &k);
	for(int i=0;i<k;i++)
	{
		arr[i]=i;
		getchar();
		scanf("%c", &c);
		A[i]=c=='<';
	}

	inequality(0);

	for(int i=0;i<=k;i++)
		printf("%d", max_arr[i]);
	printf("\n");
	for(int i=0;i<=k;i++)
		printf("%d", min_arr[i]);
	printf("\n");
	return 0;
}