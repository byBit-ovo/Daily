#include <stack>
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        stack<ListNode *> s;
        auto p = head;
        while (p != nullptr)
        {
            s.push(p);
            p = p->next;
        }

        ListNode *ans = s.top();
        while (!s.empty())
        {
            ListNode *f = s.top();
            s.pop();
            if (!s.empty())
            {
                f->next = s.top();
            }
            else
            {
                f->next = nullptr;
            }
        }
        return ans;
    }
};