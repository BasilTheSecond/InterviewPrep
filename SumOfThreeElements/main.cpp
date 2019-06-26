#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class StackItem
{
public:
    StackItem(int n, int c, vector<int> indices, vector<int> result)
    {
        this->n = n;
        this->c = c;
        this->indices = indices;
        this->result = result;
    }
    int n;
    int c;
    vector<int> indices;
    vector<int> result;
};

// iterative
void find_indices3(int n, int c, vector<int>& v, vector<int> indices, vector<int>& result, vector<vector<int>>& results)
{
    stack<StackItem> s;
    s.push(StackItem(n, c, indices, result));
    while (s.size())
    {
        StackItem item = s.top();
        s.pop();
        n = item.n;
        c = item.c;
        indices = item.indices;
        result = item.result;

        if (n == 1)
        {
            for (int i : indices)
            {
                if (v[i] == c)
                {
                    vector<int> result1 = result;
                    result1.push_back(i);
                    sort(result1.begin(), result1.end());
                    results.push_back(result1);
                }
            }
        }
        else // n > 1
        {
            while (indices.size() > 0)
            {
                int i = indices.back();
                indices.pop_back();
                vector<int> result1 = result;
                result1.push_back(i);
                s.push(StackItem(n - 1, c - v[i], indices, result1));
            }
        }
    }
}

// recursive
void find_indices2(int n, int c, vector<int>& v, vector<int> indices, vector<int>& result, vector<vector<int>>& results)
{
    if (n == 1)
    {
        for (int i : indices)
        {
            if (v[i] == c)
            {
                vector<int> result1 = result;
                result1.push_back(i);
                sort(result1.begin(), result1.end());
                results.push_back(result1);
            }
        }
    }
    else // n > 1
    {
        while (indices.size() > 0)
        {
            int i = indices.back();
            indices.pop_back();
            vector<int> result1 = result;
            result1.push_back(i);
            find_indices2(n - 1, c - v[i], v, indices, result1, results);
        }
    }
}

bool find_indices(int n, int c, vector<int>& v, vector<vector<int>>& results)
{
    vector<int> result;
    vector<int> indices;
    for (int i = 0; i < v.size(); i++)
        indices.push_back(i);
    //find_indices2(n, c, v, indices, result, results);
    find_indices3(n, c, v, indices, result, results);
    return results.size() > 0;
}

void test(const char* name, int n, int c, vector<int>& v)
{
    cout << name << endl;
    cout << "n " << n << endl;
    cout << "c " << c << endl;
    cout << "[ ";
    for (int e : v)
        cout << e << " ";
    cout << "]" << endl;
    vector<vector<int>> results;
    bool result = find_indices(n, c, v, results);
    if (result == true)
    {
        for (vector<int>& result : results)
        {
            cout << "indices [ ";
            for (int i : result)
                cout << i << " ";
            cout << "] ";
            cout << "values [";
            for (int i : result)
            {
                cout << v[i] << " ";
            }
            cout << "]" << endl;
        }
    }
    else
        cout << "No indices" << endl;
 }

int main()
{
    const char* name1 = "Test1";
    int n1 = 3;
    int c1 = 9;
    vector<int> v1 = { 6, 2, 3, 4 };
    test(name1, n1, c1, v1);

    const char* name2 = "Test2";
    int n2 = 3;
    int c2 = 14;
    vector<int> v2 = { -1, 2, 3, 6, 5, 4, 4, 89, 2, 7, 0, 7 };
    test(name2, n2, c2, v2);

    const char* name3 = "Test3";
    int n3 = 5;
    int c3 = 20;
    vector<int> v3 = { -1, 2, 3, 6, 5, 4, 4, 89, 2, 7, 0, 7 };
    test(name3, n3, c3, v3);

    const char* name4 = "Test4";
    int n4 = 3;
    int c4 = 22;
    vector<int> v4 = { -1, 2, 3, 6, 5, 4, 4, 89, 2, 7, 0, 7 };
    test(name4, n4, c4, v4);

    return 0;
}
