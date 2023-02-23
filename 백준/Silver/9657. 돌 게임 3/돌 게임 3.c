#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	bool stone[1001]={false,true,false,true,true,true,true,false, };
	int N;

	scanf("%d", &N);

	for(int n=6;n<=N;n++)
		stone[n]=!(stone[n-1]&&stone[n-3]&&stone[n-4]);

	printf("%s\n", stone[N]?"SK":"CY");
	return 0;
}