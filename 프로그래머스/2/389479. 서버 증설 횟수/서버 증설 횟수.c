#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// players_len은 배열 players의 길이입니다.
int solution(int players[], size_t players_len, int m, int k)
{
    int answer = 0, prefix_sum[48] = {0};

    for(int i = 0; i < players_len; ++i)
    {
        int required = players[i] < m ? 0 : players[i] / m;

        if(i)
            prefix_sum[i] += prefix_sum[i - 1];

        if(prefix_sum[i] < required)
        {
            int count = required - prefix_sum[i];

            prefix_sum[i] = required;
            prefix_sum[i + k] -= count;
            answer += count;
        }
    }

    return answer;
}