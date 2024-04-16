#include<stdio.h>
#include<stdbool.h>

int A, B, C;
bool visited[201][201][201]={false}, counted[201]={false};

void simulate(int a,int b,int c)
{
	if(visited[a][b][c])
		return;

	visited[a][b][c]=true;
	if(!a)
		counted[c]=true;

	if(a+b<=B)
		simulate(0,a+b,c);
	else
		simulate(a+b-B,B,c);
	if(a+c<=C)
		simulate(0,b,a+c);
	else
		simulate(a+c-C,b,C);
	if(b+c<=C)
		simulate(a,0,b+c);
	else
		simulate(a,b+c-C,C);
	if(a+b<=A)
		simulate(a+b,0,c);
	else
		simulate(A,a+b-A,c);
	if(a+c<=A)
		simulate(a+c,b,0);
	else
		simulate(A,b,a+c-A);
	if(b+c<=B)
		simulate(a,b+c,0);
	else
		simulate(a,B,b+c-B);
}

int main(void)
{
	scanf("%d%d%d", &A, &B, &C);

	simulate(0,0,C);

	for(int c=0;c<=C;++c)
		if(counted[c])
			printf("%d ", c);
	return 0;
}