  struct ListNode {
      int val;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nextHead = head;
        int i = 0;
        for(;i<k;++i)
        {
            if(nextHead==nullptr)
            {
                return head;
            }
            nextHead = nextHead->next;
        }
        
        ListNode* ans = reverseN(head,k,nextHead);
        head->next = reverseKGroup(nextHead,k);
        return ans;
        
        
        
            
    }
private:
    ListNode* reverseN(ListNode* head,int n,ListNode* nextHead)
    {
        if(n==1)
        {
            return head;
        }
        ListNode* ans = reverseN(head->next,n-1,nextHead);
        head->next->next = head;
        head->next = nextHead;
        return ans;
        
    
    }
    
};
