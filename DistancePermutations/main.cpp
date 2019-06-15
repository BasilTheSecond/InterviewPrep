#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void permute(vector<vector<int>>& list, vector<int> v, int i)
{
    if (i > v.size() / 2)
        list.push_back(v);
    else
    {
        for (int j = 0; j + i + 1 < v.size(); j++)
        {
            if (v[j] == 0 && v[j + i + 1] == 0)
            {
                vector<int> v1;
                v1.resize(v.size());
                v1 = v;
                v1[j] = v1[j + i + 1] = i;
                permute(list, v1, i + 1);
            }
        }
    }
}

void permute2(vector<vector<int>>& list, vector<int> v, int i)
{
    stack<pair<int, vector<int>>> s;
    pair<int, vector<int>> p;
    p.first = i;
    p.second = v;
    s.push(p);
    while (s.size())
    {
        p = s.top();
        s.pop();
        i = p.first;
        v = p.second;

        if(i > v.size() / 2)
            list.push_back(v);
        else
        {
            for (int j = 0; j + i + 1 < v.size(); j++)
            {
                if (v[j] == 0 && v[j + i + 1] == 0)
                {
                    vector<int> v1;
                    v1.resize(v.size());
                    v1 = v;
                    v1[j] = v1[j + i + 1] = i;
                    p.first = i + 1;
                    p.second = v1;
                    s.push(p);
                }
            }
        }
    }
}

void find_permutations(vector<vector<int>>& list, int n)
{
    vector<int> v;
    v.resize(2 * n);
    for (auto e : v)
        e = 0;
    //permute(list, v, 1);
    permute2(list, v, 1);
}

void print_permutations(vector<vector<int>>& list)
{
    if (list.size())
    {
        for (int i = 0; i < list.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < list[i].size(); j++)
                cout << " " << list[i][j] << " ";
            cout << "]\n";
        }

    }
    else
        cout << "none\n";
}

void test(const char* name, int n)
{
    cout << name << endl;
    cout << "n= " << n << endl;
    vector<vector<int>> list;
    find_permutations(list, n);
    print_permutations(list);
    cout << "\n";
}

int main()
{
    int n1 = 3;
    const char* test1 = "Test 1";
    test(test1, n1);

    int n2 = 4;
    const char* test2 = "Test 2";
    test(test2, n2);

    int n3 = 5;
    const char* test3 = "Test 3";
    test(test3, n3);

    int n4 = 6;
    const char* test4 = "Test 4";
    test(test4, n4);

    int n5 = 7;
    const char* test5 = "Test 5";
    test(test5, n5);

    return 0;
}
