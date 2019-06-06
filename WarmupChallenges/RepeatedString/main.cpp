#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Complete the repeatedString function below.
long long repeatedString(string s, long long n)
{
    if (s.size() == 0)
        return 0;
    long long occ = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'a')
            occ++;
    }
    int j = n % s.size();
    long long occ2 = 0;
    for (int i = 0; i < j; i++)
    {
        if (s.at(i) == 'a')
            occ2++;
    }
    return occ * (n / s.size()) + occ2;
}

void test(const char* inpath, const char* outpath)
{
    cout << "Test " << inpath << "\n";
    ifstream fin(inpath, ifstream::in);
    ifstream fout(outpath, ifstream::in);

    string s;
    getline(fin, s);
    long long n;
    fin >> n;
    long long actual = repeatedString(s, n);
    cout << "Input" << "\n";
    cout << s << "\n";
    cout << n << "\n";
    cout << "Output" << "\n";
    cout << "Actual " << actual << "\n";
    long long expected;
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
    test("../RepeatedString/repeated-string-testcases/input/input00.txt", "../RepeatedString/repeated-string-testcases/output/output00.txt");
    test("../RepeatedString/repeated-string-testcases/input/input01.txt", "../RepeatedString/repeated-string-testcases/output/output01.txt");
    test("../RepeatedString/repeated-string-testcases/input/input09.txt", "../RepeatedString/repeated-string-testcases/output/output09.txt");
    return 0;
}
