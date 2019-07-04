#include <iostream>
#include <map>
#include <stack>

using namespace std;
typedef string Node;
typedef float Weight;
typedef map<Node, Weight> Neighbours;
typedef map<Node, Neighbours> Graph;
typedef float Length;
typedef map<Node, Length> PathCache;

void clear_path_cache(PathCache& cache, Graph& graph)
{
    cache.clear();
    for (Graph::iterator it = graph.begin(); it != graph.end(); it++)
        cache[it->first] = -1;
}

// recursive
float find_shortest_path(Node& s, Node& t, Graph& graph, PathCache& cache)
{
    if (cache[s] < 0)
    {
        if (s == t)
            cache[s] = 0;
        else
        {
            Neighbours& neighbours = graph[s];
            float min = -1;
            for (Neighbours::iterator it = neighbours.begin(); it != neighbours.end(); it++)
            {
                Node neigbour = it->first;
                float result = it->second + find_shortest_path(neigbour, t, graph, cache);
                if (min < 0 || result < min)
                    min = result;
            }
            cache[s] = min;
        }
    }
    return cache[s];
}

// iterative
class StackItem
{
public:
    StackItem(Node& node, Weight weight, Node& neighbour)
    {
        this->node = node;
        this->weight = weight;
        this->neighbour = neighbour;
    }
    Node node;
    Weight weight;
    Node neighbour;
};

float find_shortest_path2(Node& s, Node& t, Graph& graph, PathCache& cache)
{
    stack<StackItem> stack;
    for (Neighbours::iterator it = graph[s].begin(); it != graph[s].end(); it++)
    {
        Weight weight = it->second;
        Node neighbour = it->first;
        stack.push(StackItem(s, weight, neighbour));
    }
    while (stack.size() > 0)
    {
        StackItem& item = stack.top();
        if (item.neighbour == t || cache[item.neighbour] >= 0)
        {
            if (item.neighbour == t)
                cache[item.neighbour] = 0;
            Length length = item.weight + cache[item.neighbour];
            if (cache[item.node] < 0 || cache[item.node] > length)
                cache[item.node] = length;
            stack.pop();
        }
        else
        {
            for (Neighbours::iterator it = graph[item.neighbour].begin();
                 it != graph[item.neighbour].end();
                 it++)
            {
                Weight weight = it->second;
                Node neighbour = it->first;
                stack.push(StackItem(item.neighbour, weight, neighbour));
            }
        }
    }
    return cache[s];
}

void test(const char* name, string& s, string& t, Graph& graph, float expected)
{
    cout << name << endl;
    cout << "s " << s.c_str() << endl;
    cout << "t " << t.c_str() << endl;
    cout << "graph" << endl;
    for (Graph::iterator it = graph.begin(); it != graph.end(); it++)
    {
        cout << it->first.c_str() << " [ ";
        for (Neighbours::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
            cout << "(" << it2->first.c_str() << " " << it2->second << ") ";
        cout << "]" << endl;
    }
    cout << "expected " << expected << endl;
    PathCache cache;
    clear_path_cache(cache, graph);
    //float actual = find_shortest_path(s, t, graph, cache);
    float actual = find_shortest_path2(s, t, graph, cache);
    cout << "actual " << actual << endl;
    if (expected == actual)
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
}

int main()
{
    const char* name1 = "Test1";
    Graph graph1;
    Neighbours a1;
    a1["b"] = 1;
    a1["c"] = 1;
    graph1["a"] = a1;
    Neighbours b1;
    b1["c"] = 0.5;
    b1["d"] = 2;
    graph1["b"] = b1;
    Neighbours c1;
    c1["d"] = 1;
    graph1["c"] = c1;
    Node s1 = "a";
    Node t1 = "d";
    float expected1 = 2;
    test(name1, s1, t1, graph1, expected1);

    const char* name2 = "Test2";
    Graph graph2;
    Neighbours a2;
    Neighbours b2;
    Neighbours d2;
    Neighbours e2;
    Neighbours f2;
    Neighbours h2;
    a2["b"] = 0.5;
    b2["c"] = 3;
    b2["d"] = 1;
    b2["f"] = 0.5;
    d2["e"] = 1;
    e2["g"] = 3;
    f2["e"] = 1;
    f2["h"] = 1;
    f2["g"] = 1;
    h2["g"] = 1;
    graph2["a"] = a2;
    graph2["b"] = b2;
    graph2["d"] = d2;
    graph2["e"] = e2;
    graph2["f"] = f2;
    graph2["h"] = h2;
    Node s2 = "a";
    Node t2 = "g";
    float expected2 = 2;
    test(name2, s2, t2, graph2, expected2);


    return 0;
}
