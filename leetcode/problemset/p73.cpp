#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rowSignal(m, false);
        vector<bool> colSignal(n, false);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    rowSignal[i] = colSignal[j] = true;
        for (int i = 0; i < m; i++)
            if (rowSignal[i])
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
        for (int i = 0; i < n; i++)
            if (colSignal[i])
                for (int j = 0; j < m; j++)
                    matrix[j][i] = 0;
    }
};

int main()
{
    Solution so;
    // cout << so.setZeroes() << endl;
    return 0;
}