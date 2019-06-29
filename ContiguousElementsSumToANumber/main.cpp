#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int>& v)
{
    int result = 0;
    for (int i : v)
        result += i;
    return result;
}

// iterative
void find_subarrays2(int c, vector<int>& v, vector<vector<int>>& results)
{
    while (v.size() > 0)
    {
        vector<int> v1 = v;
        vector<int> v2;
        while (v1.size() > 0)
        {
            v2.push_back(v1.front());
            v1.erase(v1.begin());
            if (sum(v2) == c)
                results.push_back(v2);
        }
        v.erase(v.begin());
    }
}

// recursive
void find_subarrays(int c, vector<int>& v, vector<vector<int>>& results)
{
    if (v.size() > 0)
    {
        vector<int> v1 = v;
        vector<int> v2;
        while (v1.size() > 0)
        {
            v2.push_back(v1.front());
            v1.erase(v1.begin());
            if (sum(v2) == c)
                results.push_back(v2);
        }
        v.erase(v.begin());
        find_subarrays(c, v, results);
    }
}

void test(const char* name, int c, vector<int>& v)
{
    vector<vector<int>> results;
    cout << name << endl;
    cout << "c " << c << endl;
    cout << "[ ";
    for (int i : v)
        cout << i << " ";
    cout << "]" << endl;
    //find_subarrays(c, v, results);
    find_subarrays2(c, v, results);
    cout << "subarrays" << endl;
    for (vector<int>& result : results)
    {
        cout << "[ ";
        for (int i : result)
            cout << i << " ";
        cout << "]" << endl;
    }
}

int main()
{
    const char* name1 = "Test1";
    int c1 = 8;
    vector<int> v1 = { 6, 5, 3, 2, 1, 7 };
    test(name1, c1, v1);

    const char* name2 = "Test2";
    int c2 = 10;
    vector<int> v2 = { 6, 5, 3, 2, 1, 7 };
    test(name2, c2, v2);

    const char* name3 = "Test3";
    int c3 = 2;
    vector<int> v3 = { -6, 5, 3, 2, 1, 7, 0, 2 };
    test(name3, c3, v3);

    return 0;
}
