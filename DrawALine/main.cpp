#include <iostream>

using namespace std;

void draw_line(char* v, int w, int h, int x1, int y1, int x2, int y2)
{
    // co-ordinates into pixels
    int pix1 = x1 + w * y1;
    int pix2 = x2 + w * y2;

    // pixels into bytes and bits
    int byte1 = pix1 / 8;
    int bit1  = 7 - pix1 % 8;
    int byte2 = pix2 / 8;
    int bit2  = 7 - pix2 % 8;

    // draw line
    for (int i = bit1; i >=0; i--)
        v[byte1] |= (1 << i);
    for (int i = byte1 + 1; i < byte2; i++)
        v[i] = 255;
    for (int i = 7; i >= bit2; i--)
        v[byte2] |= (1 << i);
}

void print(const char* v, int w, int h)
{
    int n = w / 8 * h;
    for (int i = 0; i < n; i++)
    {
        for (int j = 7; j >= 0; j--)
            cout << ((v[i] & (1 << j)) ? "1" : "0");
        cout << " ";
        if (((i + 1) * 8) % w == 0)
            cout << endl;
    }
}

void clear(char* v, int w, int h)
{
    int n = w / 8 * h;
    for (int i = 0; i < n; i++)
        v[i] = 0;
}

void test(const char* name, int w, int h, int x1, int y1, int x2, int y2)
{
    cout << name << endl;
    cout << "w " << w << ", h " << h << endl;
    cout << "x1 " << x1 << ", y1 " << y1 << endl;
    cout << "x2 " << x2 << ", y2 " << y2 << endl;
    char* v = new char[w / 8 * h];
    clear(v, w, h);
    draw_line(v, w, h, x1, y1, x2, y2);
    print(v, w, h);
    delete [] v;
}

int main()
{
    {
        const char* name = "Test1";
        int w = 16, h = 2;
        int x1 = 6, y1 = 1;
        int x2 = 10, y2 = 1;
        test(name, w, h, x1, y1, x2, y2);
    }

    {
        const char* name = "Test2";
        int w = 64, h = 16;
        int x1 = 13, y1 = 4;
        int x2 = 22, y2 = 4;
        test(name, w, h, x1, y1, x2, y2);
    }

    return 0;
}
