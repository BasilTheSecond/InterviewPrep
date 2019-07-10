#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool search(vector<int>& a, vector<int>& b, vector<int>& temp)
{
    bool terminate = true;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != i)
        {
            temp[0] = a[i];
            temp[1] = b[i];
            b[i] = -1;
            terminate = false;
            break;
        }
    }
    return terminate;
}


void reorder(vector<int>& a, vector<int>& b)
{
    bool terminate = false;
    vector<int> temp = { 0, -1 };
    while (!terminate)
    {
        if (temp[1] == -1)
        {
            terminate = search(a, b, temp);
        }
        else
        {
            int i = temp[1];
            int temp2[2] = { a[i], b[i] };
            a[i] = temp[0];
            b[i] = i;
            temp[0] = temp2[0];
            temp[1] = temp2[1];
        }
    }
}

void test(const char* name, vector<int>& a, vector<int>& b)
{
    cout << name << endl;
    cout << "a [ ";
    for (int i : a)
    {
        char c = i;
        cout << c << " ";
    }
    cout << "]" << endl;
    cout << "b [ ";
    for (int i : b)
        cout << i << " ";
    cout << "]" << endl;
    cout << "expected [ ";
    for (int i = 0; i < a.size(); i++)
    {
        vector<int>::iterator it = find(b.begin(), b.end(), i);
        char c = a[it - b.begin()];
        cout << c << " ";
    }
    cout << "]" << endl;
    reorder(a, b);
    cout << "sorted   [ ";
    for (int i : a)
    {
        char c = i;
        cout << c << " ";
    }
    cout << "]" << endl;
}

int main()
{
    const char* name1 = "Test1";
    vector<int> a1 = { 'C', 'D', 'E', 'F', 'G' };
    vector<int> b1 = { 3, 0, 4, 1, 2 };
    test(name1, a1, b1);

    const char* name2 = "Test2";
    vector<int> a2 = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    vector<int> b2 = { 2, 7, 5, 0, 1, 3, 6, 4 };
    test(name2, a2, b2);

    return 0;
}
