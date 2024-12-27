#include<stdio.h>

int main(void)
{
	int n, num;

	scanf("%d", &n);

	for(int i=0;i<3;++i)
	{
		int seven=0;

		for(int j=0;j<n;++j)
		{
			scanf("%d", &num);
			if(num==7)
				seven=1;
		}

		if(!seven)
		{
			printf("0");
			return 0;
		}
	}

	printf("777");
	return 0;
}