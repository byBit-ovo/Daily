
#include <vector>
#include <queue>
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
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](const ListNode *p1, const ListNode *p2)
        {
            return p1->val > p2->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> heap;
        for (auto &e : lists)
        {
            auto p = e;
            while (p)
            {
                heap.push(p);
                p = p->next;
            }
        }

        ListNode *dummy = new ListNode(-1);
        auto c = dummy;
        while (!heap.empty())
        {
            c->next = heap.top();
            heap.pop();
            c = c->next;
        }
        c->next = nullptr;

        return dummy->next;
    }
};