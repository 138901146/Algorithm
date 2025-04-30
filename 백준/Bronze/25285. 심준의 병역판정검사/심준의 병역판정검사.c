#include<stdio.h>

int main(void)
{
	int T;
	float height, weight, bmi;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%f%f", &height, &weight);

		bmi=10000.0*weight/height/height;

		if(height<141)
			printf("6\n");
		else if(height<146)
			printf("5\n");
		else if(height<159)
			printf("4\n");
		else if(height<161)
			printf("%d\n", 16.0<=bmi&&bmi<35.0?3:4);
		else if(height<204)
			printf("%d\n", 20.0<=bmi&&bmi<25.0?1:18.5<=bmi&&bmi<20.0||25.0<=bmi&&bmi<30.0?2:16.0<=bmi&&bmi<18.5||30.0<=bmi&&bmi<35.0?3:4);
		else
			printf("4\n");
	}

	return 0;
}