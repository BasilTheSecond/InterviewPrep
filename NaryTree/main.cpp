#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Tree
{
public:
    Tree(int nodes)
    {
        if (nodes)
        {
            next.resize(nodes);
            for (Tree* e : next)
                e = nullptr;
        }
    }
    void insert(Tree& node)
    {
        for (int i = 0; i < next.size(); i++)
        {
            if (next[i] == nullptr)
            {
                next[i] = &node;
                return;
            }
        }
    }
    int value;
    string name;
    vector<Tree*> next;
};

int count_occurences(Tree& root, int value)
{
    int result = 0;
    queue<Tree*> q;
    q.push(&root);
    while (q.size())
    {
        Tree* node = q.front();
        q.pop();
        if (node->value == value)
            result++;
        for (Tree* e : node->next)
            if (e != nullptr)
                q.push(e);
    }
    return result;
}

void print(Tree& root)
{
    queue<Tree*> q;
    q.push(&root);
    while (q.size())
    {
        Tree *node = q.front();
        q.pop();
        cout << node->name.c_str() << "(" << node->value << ") ";
        for (Tree* e : node->next)
        {
            if (e != nullptr)
            {
                cout << e->name.c_str() << " ";
                q.push(e);
            }
        }
        cout << endl;
    }
}

void test(const string& name, Tree& root, int value, int expected)
{
    cout << name.c_str() << endl;
    print(root);
    cout << "count " << value << endl;
    cout << "expected " << expected << endl;
    int result = count_occurences(root, value);
    cout << "actual " << result << endl;
    if (expected == result) cout << "PASS\n";
    else cout << "FAIL\n";
}

int main()
{
    const string test1("Test1");
    Tree node1(0);
    node1.value = -4;
    node1.name = "E";
    Tree node2(0);
    node2.value = 7;
    node2.name = "F";
    Tree node3(0);
    node3.value = 3;
    node3.name = "G";
    Tree node4(2);
    node4.value = 0;
    node4.name = "B";
    node4.insert(node1);
    node4.insert(node2);
    Tree node5(0);
    node5.value = 1;
    node5.name = "C";
    Tree node6(1);
    node6.value = 3;
    node6.name = "D";
    node6.insert(node3);
    Tree root1(3);
    root1.value = 0;
    root1.name = "A";
    root1.insert(node4);
    root1.insert(node5);
    root1.insert(node6);
    test(test1, root1, 0, 2);
    test(test1, root1, 7, 1);
    test(test1, root1, 3, 2);
    return 0;
}
