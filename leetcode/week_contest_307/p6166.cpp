#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {
        int numCnt[10]; // 统计字符串中0-9各个数字出现的次数
        for (int i = 0; i < 10; i++)
            numCnt[i] = 0;

        for (int i = 0; i < num.length(); i++)
            numCnt[num[i] - '0']++;

        string result = "";
        // 组装左半部分
        for (int i = 9; i > 0; i--)
            while (numCnt[i] > 1)
            {
                result += '0' + i;
                numCnt[i] -= 2;
            }
        if (result.length() > 0) // 对于0单独处理：两侧有非0的数时，中间随意加0；否则避免出现前导0而不加0
            while (numCnt[0] > 1)
            {
                result += '0';
                numCnt[0] -= 2;
            }
        // 组装中心可能有且仅有一个数字的情况
        bool centerSingle = false;
        for (int i = 9; i >= 0; i--)
            if (numCnt[i] > 0)
            {
                result += '0' + i;
                centerSingle = true;
                break;
            }
        // 组装右半部分
        int tempLen = result.length();
        for (int i = tempLen - 1; i >= 0; i--)
            if (centerSingle && i == tempLen - 1)
                continue;
            else
                result += result[i];

        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.largestPalindromic("444947137") << endl; // 样例1
    cout << solution.largestPalindromic("00009") << endl; // 样例2
    cout << solution.largestPalindromic("00000") << endl; // 特殊样例
    return 0;
}