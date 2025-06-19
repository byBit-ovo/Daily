#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "Stack.h"
int p_calculate(char* s)
{
    ST st;
    STInit(&st);
    while (*s != 0)
    {
        switch (*s)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        {
            int num1 = STPop(&st);
            int num2 = STPop(&st);
            STPush(&st, cal(num2, num1, *s));
            ++s;
            break;
        }
        default:
            STPush(&st,*s - '0');
            ++s;
        }
    }
    int ret = STPop(&st);
    STDestroy(&st);
    return ret;
}
int cal(int num1, int num2, char operator)
{
    switch (operator) {
    case '+':
    {
        return num1 + num2;
    }
    case '-':
    {
        return num1 - num2;
    }
    case '*':
    {
        return num1 * num2;
    }
    case '/':
    {
        return num1 / num2;
    }
    }
}
int main()
{
    char s[] = "21+3*";
    printf("%d", p_calculate(s));
    return 0;
}