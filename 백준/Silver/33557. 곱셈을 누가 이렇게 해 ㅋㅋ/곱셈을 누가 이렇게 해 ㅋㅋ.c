#include<stdio.h>
#include<string.h>

int main(void)
{
	int T, digit_A[7], digit_B[7];
	long long A, B;

	scanf("%d", &T);

	while(T--)
	{
		int digit_A[7]={0}, digit_B[7]={0}, appear_A=6, appear_B=6;
		char original[15]={0}, compare[15]={0};

		scanf("%lld%lld", &A, &B);

		sprintf(original, "%lld", A*B);

		for(int i=6;A;--i, A/=10)
			digit_A[i]=A%10;
		for(int i=6;B;--i, B/=10)
			digit_B[i]=B%10;

		for(int i=0;i<7;++i)
			if(digit_A[i])
			{
				appear_A=i;
				break;
			}
		for(int i=0;i<7;++i)
			if(digit_B[i])
			{
				appear_B=i;
				break;
			}

		if(appear_A<appear_B)
			for(int i=appear_A;i<appear_B;++i)
				digit_B[i]=1;
		else if(appear_B<appear_A)
			for(int i=appear_B;i<appear_A;++i)
				digit_A[i]=1;


		for(int i=0;i<7;++i)
		{
			if(digit_A[i]==0 && digit_B[i]==0)
				continue;

			char temp[3]={0};
			sprintf(temp, "%d", digit_A[i]*digit_B[i]);
			strcat(compare, temp);
		}

		printf("%d\n", strcmp(original,compare)?0:1);
	}

	return 0;
}