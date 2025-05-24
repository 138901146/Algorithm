#include<stdio.h>

int main(void)
{
	int n, min_index, min_value=1234567890, junk;

	scanf("%d", &n);

	for(int i=0;i<n;++i)
	{
		scanf("%d", &junk);

		if(junk<min_value)
		{
			min_index=i;
			min_value=junk;
		}
	}

	printf("%d", min_index);
	return 0;
}