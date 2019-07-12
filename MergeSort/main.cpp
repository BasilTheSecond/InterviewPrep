#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int* v, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << "]" << endl;
}

void print(vector<int>& v)
{
    cout << "[ ";
    for (int i : v)
        cout << i << " ";
    cout << "]" << endl;
}

void merge(int* v, int* temp, int n)
{
    int middle = n / 2;
    int* p1 = temp;
    int* p2 = temp + middle;

    for (int i = 0; i < n; i++)
    {
        if (p1 >= temp + middle)
        {
            v[i] = *p2++;
        }
        else if (p2 >= temp + n)
        {
            v[i] = *p1++;
        }
        else if (*p1 < *p2)
        {
            v[i] = *p1++;
        }
        else if (*p1 > *p2)
        {
            v[i] = *p2++;
        }
        else // *p1 == *p2
        {
            v[i++] = *p1++;
            v[i] = *p2++;
        }
    }
}

void msort(int* v, int n)
{
    if (n <= 1)
        return;
    int* temp = new int[n];
    for (int i = 0; i < n; i++)
        temp[i] = v[i];
    int middle = n / 2;
    msort(temp, middle);
    msort(temp + middle, n - middle);
    merge(v, temp, n);
    delete [] temp;
}

void test(const char* name, int* v, int n)
{
    cout << name << endl;
    print(v, n);
    cout << "expected" << endl;
    vector<int> expected;
    for (int i = 0; i < n; i++)
        expected.push_back(v[i]);
    sort(expected.begin(), expected.end());
    print(expected);
    msort(v, n);
    cout << "sorted" << endl;
    print(v, n);
}

int main()
{
    const char* name1 = "Test1";
    int v1[] = { 8, 5, 11, 3, 8, 10, 13, 8, 1, 12, 4 };
    int n1 = sizeof(v1) / sizeof(int);
    test(name1, v1, n1);

    const char* name2 = "Test2";
    int v2[] = { 45, 8, 3, 9, 22, 7, 3, 10, 11, 3, 1, 8, 3, 0, 45, 22, 21 };
    int n2 = sizeof(v2) / sizeof(int);
    test(name2, v2, n2);

    const char* name3 = "Test3";
    int v3[] = { 45, 8 };
    int n3 = sizeof(v3) / sizeof(int);
    test(name3, v3, n3);

    return 0;
}
