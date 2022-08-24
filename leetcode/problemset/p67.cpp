#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int aArr[10010];
        int bArr[10010];
        int cArr[10010];
        int alen = 0, blen = 0, clen = 0;
        for (int i = 0; i < 10010; i++)
            aArr[i] = bArr[i] = cArr[i] = 0;

        for (int i = a.length() - 1; i >= 0; i--)
            aArr[alen++] = a[i] - '0';
        for (int i = b.length() - 1; i >= 0; i--)
            bArr[blen++] = b[i] - '0';
        clen = max(alen, blen);

        for (int i = 0; i < clen; i++)
        {
            int sum = aArr[i] + bArr[i] + cArr[i];
            cArr[i] = sum % 2;
            cArr[i + 1] += sum / 2;
        }
        while (cArr[clen] > 0)
        {
            cArr[clen + 1] += cArr[clen] / 2;
            cArr[clen] = cArr[clen] % 2;
            clen++;
        }

        string res = "";
        for (int i = clen - 1; i >= 0; i--)
            res += '0' + cArr[i];
        return res;
    }
};

int main()
{
    string a1 = "11", b1 = "1";
    string a2 = "1010", b2 = "1011";
    Solution so;
    cout << so.addBinary(a1, b1) << endl;
    cout << so.addBinary(a2, b2) << endl;
    return 0;
}