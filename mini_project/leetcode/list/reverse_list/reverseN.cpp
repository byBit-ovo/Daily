#include <stack>
using namespace std;

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
private:
    ListNode *successor = nullptr;
public:
    ListNode *reverseList(ListNode *head,int n)
    {
        if(head==nullptr || head->next==nullptr)
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
};





