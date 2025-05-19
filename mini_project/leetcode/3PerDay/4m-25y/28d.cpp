// Definition for singly-linked list.

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


 class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* dummy = new ListNode();
            dummy->next = head;
            ListNode* cur = head,*prev=dummy;
            while(cur)
            {
                if(cur->next && cur->next->val == cur->val)
                {
                    int before = cur->val;
                    while(cur && cur->val==before)
                    {
                        cur = cur->next;
                    }
                    prev->next = cur;
                }
                else
                {
                    prev = cur;
                    cur = cur->next;
                }
            }
            return dummy->next;
        }
    };