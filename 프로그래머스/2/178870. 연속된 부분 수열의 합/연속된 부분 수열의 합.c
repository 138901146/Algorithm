#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
int *solution(int sequence[], size_t sequence_len, int k)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *)calloc(2, sizeof(int)), start = 0, sum = 0;

    answer[1] = sequence_len - 1;
    for(int end = 0; end < sequence_len; ++end)
    {
        sum += sequence[end];
        
        while(k < sum && start < end)
            sum -= sequence[start++];

        if(sum == k && end - start < answer[1] - answer[0])
        {
            answer[0] = start;
            answer[1] = end;
        }
    }

    return answer;
}