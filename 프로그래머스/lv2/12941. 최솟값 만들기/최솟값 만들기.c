#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    
	qsort((void *)A,(size_t)A_len,sizeof(int),compare);
	qsort((void *)B,(size_t)B_len,sizeof(int),compare);
    
    for(int i=0;i<A_len;++i)
        answer+=A[i]*B[A_len-i-1];
    
    return answer;
}