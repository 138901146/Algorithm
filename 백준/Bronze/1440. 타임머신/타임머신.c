#include<stdio.h>

int is_valid(int h,int m,int s)
{
	return 0<h&&h<13&&0<=m&&m<60&&0<=s&&s<60;
}

int main(void)
{
	int t[3], count=0;

	scanf("%02d:%02d:%02d", &t[0], &t[1], &t[2]);

	count+=is_valid(t[0],t[1],t[2]);
	count+=is_valid(t[0],t[2],t[1]);
	count+=is_valid(t[1],t[0],t[2]);
	count+=is_valid(t[1],t[2],t[0]);
	count+=is_valid(t[2],t[0],t[1]);
	count+=is_valid(t[2],t[1],t[0]);

	printf("%d", count);
	return 0;
}