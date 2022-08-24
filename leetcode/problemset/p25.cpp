#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *p1, ListNode *p2)
    {
        ListNode *oldHead = p1->next; // 这一段里面的旧的头部
        ListNode *newHead = p2;       // 这一段里面翻转后的新的头部
        while (oldHead != p2)
        {
            ListNode *temp = oldHead->next;
            oldHead->next = newHead;
            newHead = oldHead;
            oldHead = temp;
        }
        ListNode *newP1 = p1->next; // 翻转后p1-next就是p2的前一个
        p1->next = newHead; // vHead->next的更新也是在这里
        return newP1;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // vHead->head->...->p1->  n1->n2->...->nk  ->p2->...
        ListNode *vHead, *p1, *p2;
        vHead = new ListNode(0, head);
        p1 = vHead;
        p2 = vHead->next;

        int cnt = 0;
        while (p2 != nullptr)
        {
            cnt++;
            p2 = p2->next;
            if (cnt == k)
            {
                p1 = reverse(p1, p2);
                cnt = 0;
            }
        }

        return vHead->next;
    }
};

int main()
{
    ListNode n5 = {5, nullptr};
    ListNode n4 = {4, &n5};
    ListNode n3 = {3, &n4};
    ListNode n2 = {2, &n3};
    ListNode n1 = {1, &n2};
    ListNode *head = &n1;
    Solution so;
    head = so.reverseKGroup(head, 2);
    // head = so.reverseKGroup(head, 3);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}