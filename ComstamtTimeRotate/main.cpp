#include <iostream>
#include <vector>

using namespace std;

int find_index(int j, vector<int>& s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == j)
            return i;
    return 0;
}

void rotate_array(int k, vector<int>& s)
{
    for (int i = 0, k1 = k % s.size(); i < s.size(); i++)
    {
        if (s[k1] != i + 1)
        {
            int l = find_index(i + 1, s);
            int temp = s[k1];
            s[k1] = s[l];
            s[l] = temp;
        }
        k1 = (k1 + 1) % s.size();
    }
}

void test(const char* name, int k, vector<int>& s, vector<int>& expected)
{
    cout << name << endl;
    cout << "k " << k << endl;
    cout << "[ ";
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << "]" << endl;
    cout << "result" << endl;
    rotate_array(k, s);
    cout << "[ ";
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << "]" << endl;
    cout << "expected" << endl;
    cout << "[ ";
    for (int i = 0; i < s.size(); i++)
        cout << expected[i] << " ";
    cout << "]" << endl;
    cout << (s != expected ? "FAIL" : "PASS") << endl;
}

int main()
{
    const char* name1 = "Test1";
    int k1 = 2;
    vector<int> s1        = { 1, 2, 3, 4, 5, 6 };
    vector<int> expected1 = { 5, 6, 1, 2, 3, 4 };
    test(name1, k1, s1, expected1);

    const char* name2 = "Test2";
    int k2 = 5;
    vector<int> s2        = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> expected2 = { 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
    test(name2, k2, s2, expected2);

    const char* name3 = "Test3";
    int k3 = 95;
    vector<int> s3        = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> expected3 = { 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
    test(name3, k3, s3, expected3);

    const char* name4 = "Test4";
    int k4 = 4;
    vector<int> s4        = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> expected4 = { 7, 8, 9, 10, 1, 2, 3, 4, 5, 6 };
    test(name4, k4, s4, expected4);

    return 0;
}
