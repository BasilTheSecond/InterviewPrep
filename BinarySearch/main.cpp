#include <iostream>

#define RECURSIVE 1

using namespace std;

int middle(int size)
{
    return size / 2;
}

// iterative
bool search2(int s, int* v, int size)
{
    while (size > 1)
    {
        int m = middle(size);
        if (s == v[m])
            return true;
        else if (s < v[m])
            size = m;
        else // s > v[m]
        {
            size -= m + 1;
            v += m;
        }
    }
    if (size == 0)
        return false;
    return s == v[0];
}

// recursive
bool search(int s, int* v, int size)
{
    if (size == 0)
        return false;
    else if (size == 1)
        return s == v[0];
    int m = middle(size);
    if (s == v[m])
        return true;
    else if (s < v[m])
        return search(s, v, m);
    else // s > v[m]
        return search(s, v + m, size - m - 1);
}

void test(const char* name, int s, int* v, int size, bool expected)
{
    cout << name << endl;
    cout << "Looking for " << s << endl;
    for (int i = 0; i < size; i++)
        cout << v[i] << endl;
    //bool result = search(s, v, size);
    bool result = search2(s, v, size);
    cout << "Result " << result << endl;
    cout << "Expected " << expected << endl;
    if (result == expected)
        cout << "PASS\n";
    else
        cout << "FAIL\n";
}

int main()
{
    const char* name1 = "Test1";
    int s1 = 1;
    int v1[] = { 1 };
    int size1 = sizeof(v1) / sizeof(int);
    bool expected1 = true;
    test(name1, s1, v1, size1, expected1);

    const char* name2 = "Test2";
    int s2 = 11;
    int v2[] = { -2, 11};
    int size2 = sizeof(v2) / sizeof(int);
    bool expected2 = true;
    test(name2, s2, v2, size2, expected2);

    const char* name3 = "Test3";
    int s3 = 203;
    int v3[] = { -9, 34, 78, 100, 203, 445, 1003  };
    int size3 = sizeof(v3) / sizeof(int);
    bool expected3 = true;
    test(name3, s3, v3, size3, expected3);

    const char* name4 = "Test4";
    int s4 = 34;
    int v4[] = { -9, 34, 78, 100, 203, 445, 1003  };
    int size4 = sizeof(v4) / sizeof(int);
    bool expected4 = true;
    test(name4, s4, v4, size4, expected4);

    return 0;
}
