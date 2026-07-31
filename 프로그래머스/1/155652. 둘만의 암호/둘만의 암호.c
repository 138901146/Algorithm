#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *s, const char *skip, int index)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char *answer = (char *)calloc(strlen(s), sizeof(char));
    bool skip_required[26] = {false};

    for(int i = 0; i < strlen(skip); ++i)
        skip_required[skip[i] - 'a'] = true;

    for(int i = 0; i < strlen(s); ++i)
    {
        answer[i] = s[i];

        for(int j = 0; j < index; ++j)
        {
            ++answer[i];

            if('z' < answer[i])
                answer[i] -= 26;

            if(skip_required[answer[i] - 'a'])
                --j;
        }
    }

    return answer;
}