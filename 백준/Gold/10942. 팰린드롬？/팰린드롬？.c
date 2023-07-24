#include<stdio.h>
#include<stdbool.h>

int arr[2000], palindrome[2000][2000];

bool is_palindrome(int S,int E)
{
	if(E<=S)
		return palindrome[S][E]=1;
	else if(palindrome[S][E]!=-1)
		return palindrome[S][E];
	return palindrome[S][E]=(arr[S]==arr[E]&&is_palindrome(S+1,E-1));
}

int main(void)
{
	int N, M, S, E;

	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%d", &arr[i]);

		for(int j=0;j<N;j++)
			palindrome[i][j]=-1;
		palindrome[i][i]=1;
	}

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &S, &E);
		printf("%d\n", is_palindrome(S-1,E-1));
	}

	return 0;
}