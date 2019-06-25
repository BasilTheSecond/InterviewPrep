#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    float x;
    float y;
};

vector<struct Point> find_closest(int n, vector<struct Point>& points)
{
    vector<struct Point> result;
    vector<pair<float, struct Point>> distances;
    for (struct Point& point : points)
    {
        float distance = point.x * point.x + point.y * point.y;
        distances.push_back(pair<float, struct Point>(distance, point));
    }
    sort(distances.begin(),
         distances.end(),
         [] (const pair<float, struct Point>& p1, const pair<float, struct Point>& p2)
         {
            return p1.first <= p2.first;
         } );
    for (int i = 0; i < n; i++)
        result.push_back(Point(distances[i].second.x, distances[i].second.y));
    return result;
}

void test(const char* name, int n, vector<struct Point>& points)
{
    cout << name << endl;
    cout << "n " << n << endl;
    cout << "[ ";
    for (struct Point &point : points)
    {
        cout << " ( " << point.x << ", " << point.y << " ) ";
    }
    cout << "]" << endl;
    cout << "result" << endl;
    vector<struct Point> closest = find_closest(n, points);
    cout << "[ ";
    for (struct Point& point : closest)
    {
        cout << "( " << point.x << ", " << point.y << " ) ";
    }
    cout << "]" << endl;
}

int main()
{
    const char* name1 = "Test1";
    vector<struct Point> points = { Point(1, 1), Point(-1.2, -1.5), Point(4, 5.2), Point(2.2, 3.81), Point(-4, -17), Point(5, 7.66), Point(10, 10), Point(20, 21) };
    int n1 = 3;
    test(name1, n1, points);
    return 0;
}
