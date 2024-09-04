#include<stdio.h>

int main(void)
{
	double weight, height, BMI;

	scanf("%lf", &weight);
	scanf("%lf", &height);

	BMI=weight/(height*height);

	if(BMI<18.5)
		printf("Underweight");
	else if(25<BMI)
		printf("Overweight");
	else
		printf("Normal weight");

	return 0;
}