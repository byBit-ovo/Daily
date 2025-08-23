
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *fast = head, *slow = head;

        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        return dummy->next;
    }
};