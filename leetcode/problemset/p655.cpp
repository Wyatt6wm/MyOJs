#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height = 0;
    int m = 0, n = 0;

    int dfsGetHeight(TreeNode *now)
    {
        int nowHeight = 0;
        if (now->left != nullptr)
            nowHeight = max(nowHeight, dfsGetHeight(now->left) + 1);
        if (now->right != nullptr)
            nowHeight = max(nowHeight, dfsGetHeight(now->right) + 1);
        return nowHeight;
    }

    string numToString(int num)
    {
        if (num == 0) // 处理0的情况
            return "0";
        string s1 = "";
        string s2 = "";
        if (num < 0) // 处理负数的情况
        {
            s2 += '-';
            num = -num;
        }
        while (num > 0)
        {
            s1 += '0' + num % 10;
            num /= 10;
        }
        for (int i = s1.length() - 1; i >= 0; i--)
            s2 += s1[i];
        return s2;
    }

    void dfsPrintMatrix(vector<vector<string>> *res, TreeNode *now, int r, int c)
    {
        (*res)[r][c] += numToString(now->val);
        if (now->left != nullptr)
            dfsPrintMatrix(res, now->left, r + 1, c - (1 << (height - r - 1)));
        if (now->right != nullptr)
            dfsPrintMatrix(res, now->right, r + 1, c + (1 << (height - r - 1)));
    }

    vector<vector<string>> printTree(TreeNode *root)
    {
        height = dfsGetHeight(root);
        m = height + 1;              // m行
        n = (1 << (height + 1)) - 1; // n列

        vector<vector<string>> res(m, vector<string>(n, ""));
        dfsPrintMatrix(&res, root, 0, (n - 1) / 2);

        return res;
    }
};

int main()
{
    // 样例1
    // TreeNode node2 = {2};
    // TreeNode node1 = {1, &node2, nullptr};
    // 样例2
    // TreeNode node4 = {4};
    // TreeNode node2 = {2, nullptr, &node4};
    // TreeNode node3 = {3};
    // TreeNode node1 = {1, &node2, &node3};
    // 样例3
    TreeNode node2 = {2};
    TreeNode node1 = {1, &node2, nullptr};
    Solution solution;
    vector<vector<string>> res = solution.printTree(&node1);
    for (int i = 0; i < solution.m; i++)
    {
        for (int j = 0; j < solution.n; j++)
            if (res[i][j].length() == 0)
                cout << ". ";
            else
                cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}