
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast != slow)
        {
            if (slow)
            {
                slow = slow->next;
            }
            if (fast)
            {
                fast = fast->next;
                if (fast)
                {
                    fast = fast->next;
                }
            }
        }
        return fast != nullptr;
    }
};