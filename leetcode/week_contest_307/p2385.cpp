#include <iostream>
#include <math.h>
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
    struct Node
    {
        Node *arcs[3];
        int arcSize = 0;
        bool visited = false;
        int dist = 0; // 距离start的距离
    };
    Node *startNode = nullptr;
    Node *treeNode[100001];
    int tot = 0;

    Node *dfs(Node *father, TreeNode *now, int start)
    {
        Node *nowNode = treeNode[tot++];
        nowNode = new Node();
        if (father != nullptr)
            nowNode->arcs[nowNode->arcSize++] = father;
        if (now->left != nullptr)
            nowNode->arcs[nowNode->arcSize++] = dfs(nowNode, now->left, start);
        if (now->right != nullptr)
            nowNode->arcs[nowNode->arcSize++] = dfs(nowNode, now->right, start);
        if (now->val == start)
            startNode = nowNode;
        return nowNode;
    }

    int bfs()
    {
        int res = 0;
        Node *queue[100001];
        int head = 0;
        int rear = 0;
        queue[rear++] = startNode;
        startNode->visited = true;
        startNode->dist = 0;

        while (head < rear)
        {
            Node *now = queue[head++];
            for (int i = 0; i < now->arcSize; i++)
            {
                Node *next = now->arcs[i];
                if (!next->visited)
                {
                    queue[rear++] = next;
                    next->visited = true;
                    next->dist = now->dist + 1;
                    res = max(res, next->dist);
                }
            }
        }

        return res;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        dfs(nullptr, root, start);
        return bfs();
    }
};

int main()
{
    // 样例1
    TreeNode node9 = {9};
    TreeNode node2 = {2};
    TreeNode node4 = {4, &node9, &node2};
    TreeNode node5 = {5, NULL, &node4};
    TreeNode node10 = {10};
    TreeNode node6 = {6};
    TreeNode node3 = {3, &node10, &node6};
    TreeNode root1 = {1, &node5, &node3};
    // 样例2
    // TreeNode root2 = {1};
    Solution solution;
    cout << solution.amountOfTime(&root1, 3) << endl; // 样例1
    // cout << solution.amountOfTime(&root2, 1) << endl; // 样例2
    return 0;
}