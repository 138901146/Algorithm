#include<stdio.h>

int main(void)
{
	int T, side[3];

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		for(int i=0;i<3;++i)
		{
			scanf("%d", &side[i]);

			for(int j=0;j<i;++j)
				if(side[i]<side[j])
				{
					int temp=side[i];
					side[i]=side[j];
					side[j]=temp;
				}
		}

		printf("Case #%d: %s\n", t, side[0]*side[0]+side[1]*side[1]==side[2]*side[2]?"YES":"NO");
	}

	return 0;
}