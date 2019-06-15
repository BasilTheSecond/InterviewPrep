#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<pair<int, int>>& list)
{
    cout << "[ ";
    for (int i = 0; i < list.size(); i++)
    {
        pair<int, int> p = list[i];
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "]\n";
}

void merge_overlaps(vector<pair<int, int>>& list)
{
    vector<pair<int, int>> result;
    int a = list[0].first;
    int b = list[0].second;
    int i = 1;
    while (i < list.size())
    {
        if (b < list[i].first)
        {
            result.push_back(pair<int, int>(a, b));
            a = list[i].first;
            b = list[i].second;
        }
        else
        {
            a = min(a, list[i].first);
            b = max(b, list[i].second);
        }
        i++;
    }
    result.push_back(pair<int, int>(a, b));
    list = result;
}

int total_covered(vector<pair<int, int>>& list)
{
    sort(list.begin(), list.end());
    merge_overlaps(list);
    int result = 0;
    for (int i = 0; i < list.size(); i++)
    {
        pair<int, int> p = list[i];
        result += p.second - p.first;
    }
    return result;
}

void test(const char* name, vector<pair<int, int>>& list, int expected)
{
    cout << name << endl;
    print(list);
    int result = total_covered(list);
    cout << "expected: " << expected << endl;
    cout << "actual: " << result << endl;
    if (expected == result)
        cout << "PASS\n";
    else
        cout << "FAIL\n";
}

int main()
{
    const char* test1 = "Test1";
    vector<pair<int, int>> list1 = { pair<int, int>(1, 4), pair<int, int>(2, 3) };
    int expected1 = 3;
    test(test1, list1, expected1);

    const char* test2 = "Test2";
    vector<pair<int, int>> list2 = { pair<int, int>(4, 6), pair<int, int>(1, 2) };
    int expected2 = 3;
    test(test2, list2, expected2);

    const char* test3 = "Test3";
    vector<pair<int, int>> list3 = { pair<int, int>(1,4), pair<int, int>(6, 8), pair<int, int>(2,4), pair<int, int>(7,9), pair<int, int>(10, 15) };
    int expected3 = 11;
    test(test3, list3, expected3);
    return 0;
}
