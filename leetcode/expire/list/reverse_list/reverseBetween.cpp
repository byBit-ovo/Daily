
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fhead = dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            fhead = fhead->next;
        }

        fhead->next = reverseList(fhead->next, right - left + 1);
        return dummy->next;
    }
    ListNode *reverseList(ListNode *head, int n)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        if (n == 1)
        {
            successor = head->next;
            return head;
        }

        ListNode *ans = reverseList(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return ans;
    }

private:
    ListNode *successor = nullptr;
};



class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==1)
        {
            return reverseList(head,right-left+1);
        }
        head->next = reverseBetween(head->next,left-1,right-1);
        return head;

    }
    ListNode *reverseList(ListNode *head,int n)
    {

        if (n == 1)
        {
            successor = head->next;
            return head;
        }

        ListNode *ans = reverseList(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return ans;
    }
private:
    ListNode *successor = nullptr;
};