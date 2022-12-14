#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle = vector(numRows, vector<int>());
        for (int i = 0; i < numRows; i++)
        {
            triangle[i] = vector<int>(i + 1, 0);
            triangle[i][0] = 1;
            triangle[i][i] = 1;
            if (i > 1)
                for (int j = 1; j < i; j++)
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        return triangle;
    }
};

int main()
{
    int numRows = 30;
    Solution so;
    vector<vector<int>> res = so.generate(numRows);
    for (vector<int> row : res)
    {
        for (int col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}