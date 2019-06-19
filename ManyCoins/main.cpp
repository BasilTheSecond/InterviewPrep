#include <iostream>
#include <vector>

using namespace std;


struct Value
{
    int v;
    int i1;
    int i2;
    int i3;
};

void find_value(vector<int>& coins, vector<struct Value>& values, int v)
{
    int c1 = coins[0];
    int c2 = coins[1];
    int c3 = coins[2];
    int n1 = 1000 / c1;
    int n2 = 1000 / c2;
    int n3 = 1000 / c3;

    for (int i1 = 0; i1 <= n1; i1++)
    {
        for (int i2 = 0; i2 <= n2; i2++)
        {
            for (int i3 = 0; i3 <= n3; i3++)
            {
                if (c1 * i1 + c2 * i2 + c3 * i3 == v)
                {
                    struct Value value;
                    value.v = v;
                    value.i1 = i1;
                    value.i2 = i2;
                    value.i3 = i3;
                    values.push_back(value);
                    return;
                }
            }
        }
    }
}

void find_values(vector<int>& coins, vector<struct Value>& values)
{
    for (int v = 1; v <= 1000; v++)
    {
        find_value(coins, values, v);
    }
}

void test(const string& name, vector<int>& coins)
{
    vector<struct Value> values;
    cout << name.c_str() << endl;
    cout << "[ ";
    for (int coin : coins)
        cout << coin << " ";
    cout << "]\n";
    cout << "values" << endl;
    find_values(coins, values);
    for (struct Value value : values)
        cout << value.v << " = " << coins[0] << " * " << value.i1 << " + " << coins[1] << " * " << value.i2 << " + " << coins[2] << " * " << value.i3 << endl;
}

int main()
{
    const string name1 = "Test1";
    vector<int> coins1 = { 10, 15, 55 };
    test(name1, coins1);
}
