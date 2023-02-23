#include<stdio.h>

int main(void)
{
	int T, triangle[3];

	scanf("%d", &T);

	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &triangle[i]);

		for(int i=0;i<2;i++)
			for(int j=i+1;j<3;j++)
				if(triangle[i]>triangle[j])
				{
					int temp=triangle[i];
					triangle[i]=triangle[j];
					triangle[j]=temp;
				}

		printf("Case #%d: %s\n", t, triangle[0]+triangle[1]<=triangle[2]?"invalid!":triangle[0]==triangle[1]&&triangle[1]==triangle[2]?"equilateral":triangle[0]==triangle[1]||triangle[1]==triangle[2]?"isosceles":"scalene");
	}

	return 0;
}