#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        while (s[n - 1] == ' ')
            s[--n] = '\0';
        int len = 0;
        for (int i = n - 1; i >= 0; i--)
            if (s[i] != ' ')
                len++;
            else
                break;
        return len;
    }
};