#include<stdio.h>
#include<stdbool.h>

bool star[2187][2187]={false};

void make_star(int left,int up,int size)
{
	if(size==1)
	{
		star[left][up]=true;
		return;
	}

	for(int i=0;i<3;++i)
	{
		make_star(left+size*i/3,up,size/3);
		make_star(left+size*i/3,up+(size/3<<1),size/3);
	}
	make_star(left,up+size/3,size/3);
	make_star(left+(size/3<<1),up+size/3,size/3);
}

int main(void)
{
	int N;

	scanf("%d", &N);

	make_star(0,0,N);

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			printf("%c", star[i][j]?'*':' ');
		printf("\n");
	}

	return 0;
}