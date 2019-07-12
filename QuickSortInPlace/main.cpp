#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void print(int* v, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << "] " << endl;
}

void print(vector<int>& v)
{
    cout << "[ ";
    for (int i : v)
        cout << i << " ";
    cout << "]" << endl;
}

// iterative
class StackItem
{
public:
    StackItem(int* v, int n) : v(v), n(n) { }
    int* v;
    int n;
};

void qsort2(int* v, int n)
{
    stack<StackItem> s;
    s.push(StackItem(v, n));

    while (s.size() > 0)
    {
        StackItem item = s.top();
        s.pop();

        int* v2 = item.v;
        int n2 = item.n;

        if (n2 <= 1)
            continue;

        int eq = 0;
        int lt = 1;
        int gt = n2 - 1;

        while (lt <= gt)
        {
            if (v2[eq] < v2[lt])
            {
                int temp = v2[gt];
                v2[gt] = v2[lt];
                v2[lt] = temp;
                gt--;
            }
            else if (v2[eq] > v2[lt])
            {
                int temp = v2[eq];
                v2[eq] = v2[lt];
                v2[lt] = temp;
                eq++;
                lt++;
            }
            else // v2[eq] == v2[lt]
                lt++;

        }
        s.push(StackItem(v2, eq));
        s.push(StackItem(v2 + lt, n2 - gt - 1));
    }
}

// recursive
void qsort(int* v, int n)
{
    if (n <= 1)
        return;

    int eq = 0;
    int lt = 1;
    int gt = n - 1;
    while (lt <= gt)
    {
        if (v[eq] > v[lt])
        {
            int temp = v[eq];
            v[eq] = v[lt];
            v[lt] = temp;
            lt++;
            eq++;
        }
        else if (v[eq] == v[lt])
        {
            lt++;
        }
        else // v[eq] < v[lt]
        {
            int temp = v[gt];
            v[gt] = v[lt];
            v[lt] = temp;
            gt--;
        }
    }
    qsort(v, eq); // sort elements < pivot
    qsort(v + lt, n - gt - 1); // qsort elements > pivot
}

void test(const char* name, int v[], int n)
{
    cout << name << endl;
    print(v, n);
    vector<int> expected;
    for (int i = 0; i < n; i++)
        expected.push_back(v[i]);
    sort(expected.begin(), expected.end());
    cout << "expected" << endl;
    print(expected);
    cout << "sorted" << endl;
    //qsort(v, n);
    qsort2(v, n);
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
