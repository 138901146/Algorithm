#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int **is_palindrome=NULL, *numbers=NULL;

bool check_palindrome(int start,int end)
{
	if(end-start<1)
		return is_palindrome[start][end]=1;
	else if(is_palindrome[start][end]!=-1)
		return is_palindrome[start][end];
	return is_palindrome[start][end]=(numbers[start]==numbers[end]&&check_palindrome(start+1,end-1));
}

int main(void)
{
	int N, S, E, M;

	scanf("%d", &N);
	numbers=(int *)malloc(N*sizeof(int));
	is_palindrome=(int **)malloc(N*sizeof(int *));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &numbers[n]);
		is_palindrome[n]=(int *)malloc(N*sizeof(int));
		for(int i=0;i<N;i++)
			is_palindrome[n][i]=-1;
	}

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &S, &E);
		printf("%d\n", check_palindrome(S-1,E-1));
	}

	for(int n=0;n<N;n++)
		free(is_palindrome[n]);
	free(is_palindrome);
	free(numbers);
	return 0;
}