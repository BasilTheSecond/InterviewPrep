#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void print(vector<int>& v)
{
    cout << "[ ";
    for (int i : v)
        cout << i << " ";
    cout << "]" << endl;
}

class Item
{
public:
    Item(vector<int>&v, bool sorted = false) : v(v)
    {
        if (!sorted)
            this->sorted = v.size() == 1;
        else
            this->sorted = sorted;
    }
    vector<int> v;
    bool sorted;
};

void merge(vector<int>& v, vector<int>& v1, vector<int>& v2)
{
    int n = v.size();
    v.clear();
    for (int i = 0, i1 = 0, i2 = 0; i < n; i++)
    {
        if (i1 >= v1.size())
            v.push_back(v2[i2++]);
        else if (i2 >= v2.size())
            v.push_back(v1[i1++]);
        else if (v1[i1] > v2[i2])
            v.push_back(v2[i2++]);
        else if (v1[i1] < v2[i2])
            v.push_back(v1[i1++]);
        else // v1[i1] == v2[i2]
        {
            v.push_back(v1[i1++]);
            i++;
            v.push_back(v2[i2++]);
        }
    }
}

// iterative
void msort(vector<int>& v)
{
    if (v.size() <= 1)
        return;
    stack<Item> s;
    s.push(Item(v));
    stack<Item> s2;
    while (s.size() > 0)
    {
        if (s.top().sorted && s2.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        else if (s.top().sorted && s2.size() > 0)
        {
            vector<int> v1 = s.top().v;
            s.pop();
            vector<int> v2 = s2.top().v;
            s2.pop();
            vector<int> vv;
            vv.resize(s.top().v.size());
            s.pop();
            merge(vv, v1, v2);
            s2.push(Item(vv, true));
        }
        else if (s.top().sorted == false && s2.empty())
        {
            int nn = s.top().v.size();
            int middle = nn / 2;
            vector<int>& vv = s.top().v;
            vector<int> v1;
            for (int i = 0; i < middle; i++)
                v1.push_back(vv[i]);
            s.push(Item(v1));
            vector<int> v2;
            for (int i = middle; i < nn; i++)
                v2.push_back(vv[i]);
            s.push(Item(v2));
        }
        else // s.top().sorted == false && s2.size() > 0
        {
            Item temp = s.top();
            s.pop();
            s.push(s2.top());
            s2.pop();
            s.push(temp);
        }
    }
    v = s2.top().v;
}

void test(const char* name, vector<int>& v)
{
    cout << name << endl;
    print(v);
    cout << "expected" << endl;
    vector<int> expected;
    for (int i = 0; i < v.size(); i++)
        expected.push_back(v[i]);
    sort(expected.begin(), expected.end());
    print(expected);
    msort(v);
    cout << "sorted" << endl;
    print(v);

}

int main()
{
    {
        const char* name = "Test1";
        vector<int> v = { 8, 5, 11, 3, 8, 10, 13, 8, 1, 12, 4 };
        test(name, v);
    }

    {
        const char* name = "Test2";
        vector<int> v = { 45, 8, 3, 9, 22, 7, 3, 10, 11, 3, 1, 8, 3, 0, 45, 22, 21 };
        test(name, v);
    }

    {
        const char* name = "Test3";
        vector<int> v = { 45, 8 };
        test(name, v);
    }

    return 0;
}
