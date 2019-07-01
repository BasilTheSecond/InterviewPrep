#include <iostream>

using namespace std;

int to_int(char c)
{
    return c - '0';
}

int assign_and_compute(const char* expression)
{
    const char* p = expression;
    while (*p++ != ' ')
        ;
    const char* operand = expression;
    int operand1 = 0;
    while (*p != '+' && *p != '-')
    {
        int digit = to_int(*operand++);
        operand1 = operand1 * 10 + digit;
        p++;
    }
    const char* op = p++; // operator
    int operand2 = 0;
    while (*p++ != 0)
    {
        int digit = to_int(*operand++);
        operand2 = operand2 * 10 + digit;
    }
    int result = operand1 + (*op == '+' ? operand2 : -operand2);
    return result;
}

void test(const char* name, const char* expression, int expected)
{
    cout << name << endl;
    cout << expression << endl;
    cout << "expected " << expected << endl;
    int actual = assign_and_compute(expression);
    cout << "actual " << actual << endl;
    if (expected == actual)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}

int main()
{
    const char* name1 = "Test1";
    const char* expression1 = "123456 abc+efg";
    int expected1 = 579;
    test(name1, expression1, expected1);

    const char* name2 = "Test2";
    const char* expression2 = "1234567 abcd-efg";
    int expected2 = 667;
    test(name2, expression2, expected2);
    return 0;
}
