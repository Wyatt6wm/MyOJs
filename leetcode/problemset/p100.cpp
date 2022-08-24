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
    bool check(TreeNode *x, TreeNode *y)
    {
        if (x == nullptr && y != nullptr)
            return false;
        if (x != nullptr && y == nullptr)
            return false;
        if (x == nullptr && y == nullptr)
            return true;
        return (x->val == y->val) && check(x->left, y->left) && check(x->right, y->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return check(p, q);
    }
};

int main()
{
    // 样例1
    // TreeNode p2 = {2};
    // TreeNode p3 = {3};
    // TreeNode p1 = {1, &p2, &p3};
    // TreeNode q2 = {2};
    // TreeNode q3 = {3};
    // TreeNode q1 = {1, &q2, &q3};
    // 样例2
    // TreeNode p2 = {2};
    // TreeNode p1 = {1, &p2, nullptr};
    // TreeNode q2 = {2};
    // TreeNode q1 = {1, nullptr, &q2};
    // 样例3
    TreeNode p2 = {2};
    TreeNode p3 = {1};
    TreeNode p1 = {1, &p2, &p3};
    TreeNode q2 = {1};
    TreeNode q3 = {2};
    TreeNode q1 = {1, &q2, &q3};
    Solution so;
    cout << so.isSameTree(&p1, &q1) << endl;
    return 0;
}