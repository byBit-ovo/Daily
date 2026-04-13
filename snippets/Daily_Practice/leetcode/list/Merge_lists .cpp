// 合并有序链表

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        auto p1 = list1, p2 = list2;
        ListNode *dummy = new ListNode(101);
        ListNode *tail = dummy;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                tail->next = p1;
                tail = tail->next;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                tail = tail->next;
                p2 = p2->next;
            }
        }

        if (p1)
            tail->next = p1;
        if (p2)
            tail->next = p2;

        return dummy->next;
    }
};


class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

        return nullptr;
    }
};