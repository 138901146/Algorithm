#include<stdio.h>

int main(void)
{
	int js, ij;

	scanf("%d%d", &js, &ij);

	switch(js)
	{
		case 0:
			printf("%c", ij==5?'<':ij==0?'=':'>');
			break;
		case 2:
			printf("%c", ij==0?'<':ij==2?'=':'>');
			break;
		case 5:
			printf("%c", ij==2?'<':ij==5?'=':'>');
			break;
		default:
			printf("%c", ij==0||ij==2||ij==5?'<':'=');
			break;
	}

	return 0;
}