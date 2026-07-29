#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char *s)
{
    int length = strlen(s), answer = 0, count[6] = {0};

    for(int i = 0; i < length; ++i)
        switch(s[i])
        {
            case '[':
                ++count[0];
                break;
            case ']':
                ++count[1];
                break;
            case '{':
                ++count[2];
                break;
            case '}':
                ++count[3];
                break;
            case '(':
                ++count[4];
                break;
            case ')':
                ++count[5];
                break;
        }

    for(int i = 0; i < 6; i += 2)
        if(count[i] != count[i + 1])
            return 0;

    for(int start = 0; start < length; ++start)
    {
        bool available = true;
        char stack[1000];
        int top = 0;

        for(int i = 0; i < length && available; ++i)
        {
            switch(s[(start + i) % length])
            {
                case '[':
                case '{':
                case '(':
                    stack[top++] = s[(start + i) % length];
                    break;
                case ']':
                    if(top == 0 || stack[--top] != '[')
                        available = false;
                    break;
                case '}':
                    if(top == 0 || stack[--top] != '{')
                        available = false;
                    break;
                case ')':
                    if(top == 0 || stack[--top] != '(')
                        available = false;
                    break;
            }
        }

        answer += available;
    }

    return answer;
}