
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
    ListNode *slow = nullptr;
    bool isPalindrome(ListNode *head)
    {
        slow = head;
        ListNode *fast = head;
        return back_track(fast);
    }

    bool back_track(ListNode *fast)
    {
        if (!fast->next)
        {
            int slowval = slow->val;
            slow = slow->next;
            return fast->val == slowval;
        }
        if (!back_track(fast->next))
        {
            return false;
        }
        int slowval = slow->val;
        slow = slow->next;
        return fast->val == slowval;
    }
};