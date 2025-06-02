#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        std::stack<int> s1, s2;
        auto p1 = l1;
        auto p2 = l2;
        int ans = 0;
        while (p1 != nullptr)
        {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2 != nullptr)
        {
            s2.push(p2->val);
            p2 = p2->next;
        }

        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        while (!s1.empty() || !s2.empty() || carry)
        {
            int a = 0, b = 0;
            if (!s1.empty())
            {
                a = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                b = s2.top();
                s2.pop();
            }
            int now = (carry + a + b) % 10;
            carry = (carry + a + b) / 10;
            ListNode *s = new ListNode(now);
            s->next = dummy->next;
            dummy->next = s;
        }
        return dummy->next;
    }
};