#include <iostream>
#include <string.h>
#include <stdlib.h>

int get_depth(const char* expression)
{
    int result = 0;
    int level = 0;
    while (*expression)
    {
        if (*expression == '[')
            level++;
        else if (*expression == ']')
            level--;
        expression++;
        if (level > result)
            result = level;
    }
    return result;
}

int get_int_size(const char* expression)
{
    int result = 0;
    while (*expression != ']' && *expression != ',')
    {
        result++;
        expression++;
    }
    return result;
}

int get_int(const char* expression)
{
    int size = get_int_size(expression);
    char value[256];
    memcpy(value, expression, size);
    value[size] = 0;
    int result = strtol(value, NULL, 10);
    return result;
}

int add(const char* expression)
{
    int result = 0;
    int depth = get_depth(expression);
    int weight = depth + 1;
    while (*expression)
    {
        if (*expression == '[')
            weight--;
        else if (*expression == ']')
            weight++;
        else if (*expression == ',' || *expression == ' ')
            ; // ignore
        else // Int
        {
            int value = get_int(expression);
            result += value * weight;
        }
        expression++;
    }
    return result;
}

void test(const char* test, const char* expression, int expected)
{
    std::cout << test << std::endl;
    std::cout << expression << std::endl;
    int result = add(expression);
    std::cout << "result " << result << std::endl;
    std::cout << "expected " << expected << std::endl;
    if (result == expected)
        std::cout << "OK" << std::endl;
    else
        std::cout << "FAIL!!!" << std::endl;
}

int main()
{
    const char* expression1 = "[[1,1],2,[1,1]]";
    int expected1 = 1*1 + 1*1 + 2*2 + 1*1 + 1*1;
    test("Test1", expression1, expected1);

    const char* expression2 = "[1,[4,[6]]]";
    int expected2 = 3*1 + 2*4 + 1*6;
    test("Test2", expression2, expected2);

    const char* expression3 = "[1,[1,[1,[1,1]]]]";
    int expected3 = 4*1 + 3*1 + 2*1 + 1*1 + 1*1;
    test("Test3", expression3, expected3);
}
