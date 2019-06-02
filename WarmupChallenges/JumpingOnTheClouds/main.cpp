#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {

    int steps = 0;
    int n = c.size();
    for (int i = 0; i < n;) {
        if (i + 1 < n && c[i + 1] == 1)
            i += 2;
        else if (i + 1 < n && c[i + 1] == 0)
        {
            if (i + 1 == n - 1)
                i++;
            else if (c[i + 2] == 1)
                i++;
            else if (c[i + 2] == 0)
                i += 2;
        }
        else
            break;
        steps++;
    }
    return steps;
}

void test(const char* inpath, const char* outpath)
{
    cout << "Test " << inpath << "\n";
    //ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin(inpath, ifstream::in);
    ifstream fout(outpath, ifstream::in);

    int n;
    fin >> n;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(fin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int actual = jumpingOnClouds(c);
    cout << "Input" << "\n";
    cout << n << "\n";
    for (auto e : c)
        cout << e << "\n";
    cout << "Outputs" << "\n";
    cout << "Actual " << actual << "\n";
    int expected;
    fout >> expected;
    cout << "Expected " << expected << "\n";
    if (actual == expected)
        cout << "OK\n";
    else
        cout << "FAIL!!!\n";

    fin.close();
    fout.close();
}

int main()
{
    test("../JumpingOnTheClouds/jumping-on-the-clouds-testcases/input/input00.txt", "../JumpingOnTheClouds/jumping-on-the-clouds-testcases/output/output00.txt");
    test("../JumpingOnTheClouds/jumping-on-the-clouds-testcases/input/input01.txt", "../JumpingOnTheClouds/jumping-on-the-clouds-testcases/output/output01.txt");
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
