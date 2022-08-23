#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    map<int, string> m;

    string getRomanChar(int x, int k)
    {
        switch (x / k)
        {
        case 1:
            return m[1 * k]; // 1-I 10-X 100-C 1000-M
        case 2:
            return m[1 * k] + m[1 * k]; // 2-II 20-XX 200-CC 2000-MM
        case 3:
            return m[1 * k] + m[1 * k] + m[1 * k]; // 3-III 30-XXX 300-CCC 3000-MMM
        case 4:
            return m[1 * k] + m[5 * k]; // 4-IV 40-XL 400-CD
        case 5:
            return m[5 * k]; // 5-V 50-L 500-D
        case 6:
            return m[5 * k] + m[1 * k]; // 6-VI 60-LX 600-DC
        case 7:
            return m[5 * k] + m[1 * k] + m[1 * k]; // 7-VII 70-LXX 700-DCC
        case 8:
            return m[5 * k] + m[1 * k] + m[1 * k] + m[1 * k]; // 8-VIII 80-LXXX 800-DCCC
        case 9:
            return m[1 * k] + m[10 * k]; // 9-IX 90-XC 900-CM
        default:
            return "";
        }
    }

    string intToRoman(int num)
    {
        m[0] = "";
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";

        string chars[5];
        int size = 0;
        int factor = 1;
        while (num > 0)
        {
            int x = (num % 10) * factor;
            chars[size++] = getRomanChar(x, factor);
            num /= 10;
            factor *= 10;
        }

        string res = "";
        for (int i = size - 1; i >= 0; i--)
            res += chars[i];

        return res;
    }
};

int main()
{
    Solution so;
    cout << so.intToRoman(3) << endl;
    cout << so.intToRoman(4) << endl;
    cout << so.intToRoman(9) << endl;
    cout << so.intToRoman(58) << endl;
    cout << so.intToRoman(1994) << endl;
    return 0;
}