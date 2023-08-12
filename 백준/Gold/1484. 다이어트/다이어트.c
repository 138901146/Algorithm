#include<stdio.h>

int main(void)
{
	int G, count=0;
	long long left=1, right=2, diet[50002];

	scanf("%d", &G);

	while(left<right)
	{
		if(right*right-left*left==G)
			diet[count++]=right++;
		else if(right*right-left*left<G)
			right++;
		else
			left++;
	}

	if(count==0)
		printf("-1\n");
	else
		for(int i=0;i<count;i++)
			printf("%lld\n", diet[i]);
	return 0;
}