struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		int size = 0;
		{
			auto node = head;

			while (node && ++size)
				node = node->next;
		}

		if (size == n)
			return head->next;

		auto node = head;
		for (int i{ 0 }; i < size - n - 1; i++)
			node = node->next;

		node->next = node->next->next;

		return head;
	}
};