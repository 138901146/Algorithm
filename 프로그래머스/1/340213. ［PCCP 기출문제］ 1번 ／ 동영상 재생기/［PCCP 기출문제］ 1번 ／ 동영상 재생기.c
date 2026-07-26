#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int calculate_time(const char *str)
{
    return 60 * (10 * (str[0] - '0') + (str[1] - '0')) + 10 * (str[3] - '0') + (str[4] - '0');
}

// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *video_len, const char *pos, const char *op_start, const char *op_end, const char *commands[], size_t commands_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int current = calculate_time(pos), end = calculate_time(video_len), opening_start = calculate_time(op_start), opening_end = calculate_time(op_end);
    char *answer = (char *)calloc(5, sizeof(char));

    for(int i = 0; i < commands_len; ++i)
    {
        if(opening_start <= current && current <= opening_end)
            current = opening_end;

        if(commands[i][0] == 'p')
        {
            current -= 10;
            current = current < 0 ? 0 : current;
        }
        else
        {
            current += 10;
            current = end < current ? end : current;
        }

        if(opening_start <= current && current <= opening_end)
            current = opening_end;
    }

    sprintf(answer, "%02d:%02d", current / 60, current % 60);

    return answer;
}