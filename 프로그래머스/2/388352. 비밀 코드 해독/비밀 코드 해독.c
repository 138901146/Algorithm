#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int size, arr[5], answer = 0, *output_data, m;
bool data[10][31] = {false};

bool simulation(void)
{
    for(int i = 0; i < m; ++i)
    {
        int count = 0;

        for(int j = 0; j < 5; ++j)
            count += data[i][arr[j]];

        if(count != output_data[i])
            return false;
    }

    return true;
}

void combination(int current)
{
    if(current == 0)
        for(int i = 1; i <= size; ++i)
        {
            arr[0] = i;
            combination(1);
        }
    else if(current == 5)
        answer += simulation();
    else
        for(int i = arr[current - 1] + 1; i <= size; ++i)
        {
            arr[current] = i;
            combination(current + 1);
        }
}

// q_rows는 2차원 배열 q의 행 길이, q_cols는 2차원 배열 q의 열 길이입니다.
// ans_len은 배열 ans의 길이입니다.
int solution(int n, int **q, size_t q_rows, size_t q_cols, int ans[], size_t ans_len)
{
    size = n;
    output_data = ans;
    m = q_rows;
    for(int i = 0; i < q_rows; ++i)
        for(int j = 0; j < 5; ++j)
            data[i][q[i][j]] = true;

    combination(0);

    return answer;
}