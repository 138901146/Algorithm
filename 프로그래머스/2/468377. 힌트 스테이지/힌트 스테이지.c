#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 999999999
#define MIN(x,y) ((x) < (y) ? (x) : (y))

int hint_count[16] = {0}, min = INF, n, k, **cost_global = NULL, **hint_global = NULL;

void simulation(int stage, int total)
{
    if(stage == n)
    {
        min = total < min ? total : min;
        return;
    }

    simulation(stage + 1, total + cost_global[stage][MIN(hint_count[stage], n - 1)]);

    for(int i = 1; i < k; ++i)
        ++hint_count[hint_global[stage - 1][i] - 1];
    simulation(stage + 1, total + cost_global[stage][MIN(hint_count[stage], n - 1)] + hint_global[stage - 1][0]);
    for(int i = 1; i < k; ++i)
        --hint_count[hint_global[stage - 1][i] - 1];
}

// cost_rows는 2차원 배열 cost의 행 길이, cost_cols는 2차원 배열 cost의 열 길이입니다.
// hint_rows는 2차원 배열 hint의 행 길이, hint_cols는 2차원 배열 hint의 열 길이입니다.
int solution(int **cost, size_t cost_rows, size_t cost_cols, int **hint, size_t hint_rows, size_t hint_cols)
{
    n = cost_rows;
    k = hint_cols;
    cost_global = cost;
    hint_global = hint;

    simulation(1, cost[0][0]);

    return min;
}