#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int sum(vector<int>& v)
{
    int result = 0;
    for (int i : v)
        result += i;
    return result;
}

int find_max(int k, vector<int>& v, vector<int>& result)
{
    vector<vector<int>> results;
    while (v.size() > 0)
    {
        vector<int> v1 = v;
        v1.erase(v1.begin());
        while (v1.size() >= k - 1)
        {
            vector<int> v2 = { v[0] };
            for (int i = 0; i < k - 2; i++)
                v2.push_back(v1[i]);
            for (int i = k - 2; i < v1.size(); i++)
            {
                vector<int> v3 = v2;
                v3.push_back(v1[i]);
                results.push_back(v3);
            }
            v1.erase(v1.begin());
        }
        v.erase(v.begin());
    }
    int max = numeric_limits<int>::min();
    for (vector<int>& r : results)
    {
        int s = sum(r);
        if (s > max)
        {
            max = s;
            result = r;
        }
    }
    return max;
}

void test(const char* name, int k, vector<int>& v)
{
    cout << name << endl;
    cout << "k " << k << endl;
    cout << "[ ";
    for (int i: v)
        cout << i << " ";
    cout << "]" << endl;
    vector<int> result;
    int max = find_max(k, v, result);
    cout << "max " << max << endl;
    cout << "[ ";
    for (int i : result)
        cout << i << " ";
    cout << "]" << endl;
}

int main()
{
    const char* name1 = "Test1";
    int k1 = 3;
    vector<int> v1= { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    test(name1, k1, v1);

    const char* name2 = "Test2";
    int k2 = 4;
    vector<int> v2= { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    test(name2, k2, v2);

    return 0;
}
