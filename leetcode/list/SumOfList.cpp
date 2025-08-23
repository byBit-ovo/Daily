/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* c1=l1,*c2=l2;
        int next = 0;
        
        while(c1 || c2 || next)
        {
            int a = c1?c1->val:0;
            int b = c2?c2->val:0;
            if(c1) c1=c1->next;
            if(c2) c2 =c2->next;
            int curr = (a+b+next)%10;
            next = (a+b+next)/10;
            tail->next = new ListNode(curr);
            tail=tail->next;
        }
        
        return reverse(dummy->next);
    }
private:
    ListNode* reverse(ListNode* head)
    {
        if(head || head->next) return head;
        
        ListNode* ans = reverse(head->next);
        head->next->next = head;
        head->next= nullptr;
        return ans;
    }
};