#include <iostream>
#include <string.h>

using namespace std;

bool is_periodic(const char* str, int size)
{
    int i = 0;
    while (str[i])
    {
        if (strncmp(str, str + i, size) != 0)
            return false;
        i += size;
    }
    return true;
}

int get_substr_size(const char* str)
{
    int size = 1;
    while (!is_periodic(str, size))
        size++;
    return size;
}

void test(const char* name, const char* str, int n, const char* p)
{
    cout << name << endl;
    cout << str << endl;
    cout << "Expected" << endl;
    cout << "N=" << n << endl;
    cout << "P=" << p << endl;
    cout << "Actual" << endl;
    int size = get_substr_size(str);
    int n1 = strlen(str) / size;
    string p1(str, size);
    cout << "N=" << n1 << endl;
    cout << "P=" << p1.c_str() << endl;
    if (n1 == n && string(p) == p1)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}

int main()
{
    const char* name1 = "Test1";
    const char* string1 = "ababab";
    int n1 = 3;
    const char* p1 = "ab";
    test(name1, string1, n1, p1);

    const char* name2 = "Test2";
    const char* string2 = "xxxxxx";
    int n2 = 6;
    const char* p2 = "x";
    test(name2, string2, n2, p2);

    const char* name3 = "Test3";
    const char* string3 = "aabbaaabba";
    int n3 = 2;
    const char* p3 = "aabba";
    test(name3, string3, n3, p3);

    const char* name4 = "Test4";
    const char* string4 = "aabbaazZabbaaabbaazZabbaaabbaazZabbaaabbaazZabba";
    int n4 = 4;
    const char* p4 = "aabbaazZabba";
    test(name4, string4, n4, p4);

    const char* name5 = "Test5";
    const char* string5 = "abcdefg12345";
    int n5 = 1;
    const char* p5 = "abcdefg12345";
    test(name5, string5, n5, p5);
}
