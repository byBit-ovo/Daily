
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(101);
        ListNode *dummy2 = new ListNode(101);
        auto t1 = dummy1;
        auto t2 = dummy2;
        auto p = head;
        while (p)
        {
            if (p->val < x)
            {
                t1->next = p;
                t1 = t1->next;
            }
            else
            {
                t2->next = p;
                t2 = t2->next;
            }
            p = p->next;
        }
        t1->next = dummy2->next;
        t2->next = nullptr;

        return dummy1->next;
    }
};