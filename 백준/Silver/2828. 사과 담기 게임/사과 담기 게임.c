#include<stdio.h>

int main(void)
{
	int N, M, basket_left=1, basket_right, J, count=0;

	scanf("%d %d", &N, &M);
	scanf("%d", &J);
	basket_right=M;

	for(int i=0;i<J;i++)
	{
		int apple_location;

		scanf("%d", &apple_location);

		while(!(apple_location<=basket_right && apple_location>=basket_left))
		{
			if(apple_location<basket_left)
			{
				basket_left--;
				basket_right--;
			}
			else
			{
				basket_left++;
				basket_right++;
			}
			count++;
		}
	}

	printf("%d", count);

	return 0;
}