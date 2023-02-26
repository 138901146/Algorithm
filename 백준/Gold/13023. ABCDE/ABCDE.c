#include<stdio.h>
#include<stdbool.h>

bool found=false, list[2001]={false, };
int friend[2001][2001]={0, };

bool find_friend(int N,int depth)
{
	if(depth==5)
	{
		found=true;
		return true;
	}

	for(int i=1;i<=friend[N][0];i++)
	{
		if(found)
			return true;
		if(!list[friend[N][i]])
		{
			list[friend[N][i]]=true;
			find_friend(friend[N][i],depth+1);
			list[friend[N][i]]=false;
		}
	}

	return found;
}

int main(void)
{
	int N, M, a, b;
	bool search=false;

	scanf("%d%d", &N, &M);

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &a, &b);

		friend[a][++friend[a][0]]=b;
		friend[b][++friend[b][0]]=a;
	}

	for(int n=1;n<N;n++)
	{
		if(friend[n][0]>0)
		{
			list[n]=true;
			search|=find_friend(n,1);
			list[n]=false;
		}
		if(search)
			break;
	}

	printf("%d\n", search);
	return 0;
}