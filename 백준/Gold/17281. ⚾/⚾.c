#include<stdio.h>
#include<stdbool.h>

int permutation[8]={1,2,3,4,5,6,7,8};

bool next_permutation(void)
{
	for(int i=6;i>=0;--i)
		if(permutation[i]<permutation[i+1])
		{
			int j=7;

			while(permutation[j]<permutation[i])
				--j;

			int temp=permutation[i];
			permutation[i]=permutation[j];
			permutation[j]=temp;

			for(j=1;j<=(8-i)>>1;++j)
			{
				temp=permutation[i+j];
				permutation[i+j]=permutation[8-j];
				permutation[8-j]=temp;
			}

			return true;
		}

	return false;
}

int main(void)
{
	int N, max=0, order[50][9];

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		for(int i=0;i<9;++i)
			scanf("%d", &order[n][i]);

	do
	{
		int score=0, innings=0, out=0, runner=0, mount=0, base[3]={0};

		while(innings<N)
		{
			if(runner%9<3)
				mount=permutation[(runner-runner/9)%8];
			else if(runner%9>3)
				mount=permutation[(runner-runner/9-1)%8];
			else
				mount=0;
				
			switch(order[innings][mount])
			{
				case 0:
					if(++out==3)
					{
						out=0;
						++innings;
						base[0]=base[1]=base[2]=0;
					}
					break;
				case 1:
					score+=base[2];
					base[2]=base[1];
					base[1]=base[0];
					base[0]=1;
					break;
				case 2:
					score+=base[1]+base[2];
					base[2]=base[0];
					base[1]=1;
					base[0]=0;
					break;
				case 3:
					score+=base[0]+base[1]+base[2];
					base[2]=1;
					base[1]=base[0]=0;
					break;
				case 4:
					score+=base[0]+base[1]+base[2]+1;
					base[0]=base[1]=base[2]=0;
					break;
			}
			++runner;
		}

		max=max<score?score:max;
	}
	while(next_permutation());

	printf("%d", max);
	return 0;
}