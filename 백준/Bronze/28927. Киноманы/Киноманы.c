#include<stdio.h>

int main(void)
{
	int input[2][3], output[2];

	for(int i=0;i<2;++i)
	{
		for(int j=0;j<3;++j)
			scanf("%d", &input[i][j]);
		output[i]=3*input[i][0]+20*input[i][1]+120*input[i][2];
	}

	printf("%s", output[0]>output[1]?"Max":output[0]<output[1]?"Mel":"Draw");
	return 0;
}