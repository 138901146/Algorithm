#include<stdio.h>

int arr[100000], count[100001]={0};

int main(void)
{
	int N, left=0, right;
	long long answer=0;

	scanf("%d", &N);

	for(right=0;right<N;++right)
	{
		scanf("%d", &arr[right]);

		++count[arr[right]];

		while(left<right&&(count[arr[left]]!=1||count[arr[right]]!=1))
			--count[arr[left++]];

		answer+=right-left+1;
	}

	printf("%lld", answer);
	return 0;
}