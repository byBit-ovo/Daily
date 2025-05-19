
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto dummy = new ListNode(101);
        dummy->next = head;
        auto prev = dummy;
        auto p = head;
        while (p)
        {
            if (p->next && p->val == p->next->val)
            {
                int dup_num = p->val;
                while (p && p->val == dup_num)
                {
                    p = p->next;
                }
                prev->next = p;
            }
            else
            {
                prev = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};

class Solution2 {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(!head || !head->next)
            {
                return head;
            }
    
            int dup_num = head->val;
    
            if(head->next->val != dup_num)
            {
                head->next = deleteDuplicates(head->next);
            }
            else
            {
                while(head && head->val==dup_num)
                {
                    head=head->next;
                }
                head = deleteDuplicates(head);
            }
    
            return head;
    
            
        }
    };