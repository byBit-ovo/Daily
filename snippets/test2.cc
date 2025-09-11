
ListNode* reverse(ListNode* node)
{
	if(node == nullptr || node->next == nullptr)
	{
		return node;
	}
	ListNode* head = node;
	ListNode* ret = reverse(node->next);
	node->next->next = head;
	node->next = nullptr;
	return ret;
}