#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    std::sort(ar.begin(), ar.end());
    int pairs = 0;
    int same = 0;
    int previous = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << "ar[" << i << "] " << ar[i] << endl;
        //cout << "previous " << previous << endl;
        if (previous != ar[i])
        {
            pairs += same / 2;
            same = 1;
            previous = ar[i];
        }
        else
            same++;
        //cout << "pairs " << pairs << " same " << same << endl;
    }
    pairs +=  same / 2;
    return pairs;
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

    string ar_temp_temp;
    getline(fin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int actual = sockMerchant(n, ar);
    cout << "Input" << "\n";
    cout << n << "\n";
    for (auto e : ar)
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
    test("../SockMerchant/sock-merchant-testcases/input/input00.txt", "../SockMerchant/sock-merchant-testcases/output/output00.txt");
    test("../SockMerchant/sock-merchant-testcases/input/input08.txt", "../SockMerchant/sock-merchant-testcases/output/output08.txt");

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
