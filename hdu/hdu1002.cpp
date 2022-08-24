#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_LEN 1010

int a[MAX_LEN];
int b[MAX_LEN];
int c[MAX_LEN];
int alen, blen, clen;

string calculate(string aStr, string bStr)
{
    // 初始化
    for (int i = 0; i < MAX_LEN; i++)
        a[i] = b[i] = c[i] = 0;
    alen = blen = clen = 0;    

    // string to int array and reverse
    for (int i = aStr.length() - 1; i >= 0; i--)
        a[alen++] = aStr[i] - '0';
    for (int i = bStr.length() - 1; i >= 0; i--)
        b[blen++] = bStr[i] - '0';
    clen = max(alen, blen);

    // 逐位相加并处理进位
    for (int i = 0; i < clen; i++)
    {
        int sum = a[i] + b[i] + c[i];
        c[i] = sum % 10;
        c[i + 1] += sum / 10;
    }
    while (c[clen] > 0)
    {
        c[clen + 1] += c[clen] / 10;
        c[clen] = c[clen] % 10;
        clen++;
    }

    // int array reverse and to string
    string res = "";
    for (int i = clen - 1; i >= 0; i--)
        res += '0' + c[i];
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string a = "", b = "";
        cin >> a >> b;
        cout << "Case " << i << ":" << endl;
        cout << a << " + " << b << " = " << calculate(a, b) << endl;
        if (i < t)
            cout << endl;
    }

    return 0;
}