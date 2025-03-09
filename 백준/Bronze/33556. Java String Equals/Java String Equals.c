#include<stdio.h>
#include<string.h>

int main(void)
{
	char A[101]={0}, B[101]={0};

	scanf("%s", A);
	scanf("%s", B);

	if(strcmp(A,"null")==0)
		printf("NullPointerException\nNullPointerException");
	else if(strcmp(B,"null")==0)
		printf("false\nfalse");
	else if(strcmp(A,B)==0)
		printf("true\ntrue");
	else
	{
		for(int i=0;A[i];++i)
			if('A'<=A[i] && A[i]<='Z')
				A[i]+=32;
		for(int i=0;B[i];++i)
			if('A'<=B[i] && B[i]<='Z')
				B[i]+=32;
		printf("false\n%s", strcmp(A,B)?"false":"true");
	}

	return 0;
}