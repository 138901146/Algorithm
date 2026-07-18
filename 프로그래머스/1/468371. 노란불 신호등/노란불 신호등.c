#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    if(x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    while(y)
    {
        int temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

// signals_rows는 2차원 배열 signals의 행 길이, signals_cols는 2차원 배열 signals의 열 길이입니다.
int solution(int** signals, size_t signals_rows, size_t signals_cols)
{
    int lcm_value = 1, *current_index = calloc(signals_rows, sizeof(int)), *signals_length = malloc(signals_rows * sizeof(int));

    for(int i = 0; i < signals_rows; ++i)
    {
        signals_length[i] = signals[i][0] + signals[i][1] + signals[i][2];
        lcm_value = lcm(lcm_value, signals_length[i]);
    }

    for(int i = 1; i <= lcm_value; ++i)
    {
        bool yellow = true;

        for(int j = 0; j < signals_rows; ++j)
        {
            if(current_index[j] < signals[j][0] || signals[j][0] + signals[j][1] <= current_index[j])
                yellow = false;

            current_index[j] = (current_index[j] + 1) % signals_length[j];
        }

        if(yellow)
        {
            free(current_index);
            free(signals_length);

            return i;
        }
    }

    free(current_index);
    free(signals_length);

    return -1;
}