#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr)
{
    vector<vector<vector<int>>> hg(4);
    for (int i = 0; i < 4; i ++)
    {
        hg[i].resize(4);
        for (int j = 0; j < 4; j++)
        {
            hg[i][j].resize(7);

              hg[i][j][0] = arr[i]  [j];
              hg[i][j][1] = arr[i]  [j+1];
              hg[i][j][2] = arr[i]  [j+2];
              hg[i][j][3] = arr[i+1][j+1];
              hg[i][j][4] = arr[i+2][j];
              hg[i][j][5] = arr[i+2][j+1];
              hg[i][j][6] = arr[i+2][j+2];
              //     hg[i][j]
              //     arr[i]  [j] + arr[i]  [j+1] + arr[i]  [j+2]
              //                 + arr[i+1][j+1]
              //   + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
        }
    }
    vector<vector<int>> hgSum(4);
    for (int i = 0; i < 4; i++)
    {
        hgSum[i].resize(4);
        for (int j = 0; j < 4; j++)
        {
            hgSum[i][j] = 0;
            for (int k = 0; k < 7; k++)
               hgSum[i][j] +=  hg[i][j][k];
        }
    }
    int max = 7 * (-9);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (hgSum[i][j] > max)
                max = hgSum[i][j];
    return max;
}

void test(const char* inpath, const char* outpath)
{
    cout << "Test " << inpath << "\n";
    ifstream fin(inpath, ifstream::in);
    ifstream fout(outpath, ifstream::in);
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            fin >> arr[i][j];
        }

        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int actual = hourglassSum(arr);
    cout << "Input" << "\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Output" << "\n";
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
    test("../2DArrayDS/2d-array-testcases/input/input00.txt", "../2DArrayDS/2d-array-testcases/output/output00.txt");
    test("../2DArrayDS/2d-array-testcases/input/input01.txt", "../2DArrayDS/2d-array-testcases/output/output01.txt");
    test("../2DArrayDS/2d-array-testcases/input/input03.txt", "../2DArrayDS/2d-array-testcases/output/output03.txt");
    test("../2DArrayDS/2d-array-testcases/input/input07.txt", "../2DArrayDS/2d-array-testcases/output/output07.txt");
    test("../2DArrayDS/2d-array-testcases/input/input08.txt", "../2DArrayDS/2d-array-testcases/output/output08.txt");
    return 0;
}
