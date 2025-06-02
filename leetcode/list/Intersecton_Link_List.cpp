
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        auto p1 = headA, p2 = headB;
        while (p1 != p2)
        {
            if (p1)
                p1 = p1->next;
            else
                p1 = headB;

            if (p2)
                p2 = p2->next;
            else
                p2 = headA;
        }


        return p1;
    }
};

class Solution2 {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            set<ListNode*> hash;
            while(headA)
            {
                hash.insert(headA);
                headA = headA->next;
            }
    
            while(headB)
            {
                if(hash.count(headB))
                {
                    return headB;
                }
                headB = headB->next;
            }
            return nullptr;
        }
    };