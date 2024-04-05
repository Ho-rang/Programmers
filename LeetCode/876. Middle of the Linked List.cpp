#include "pch.h"

class Solution
{
public:
	ListNode* middleNode(ListNode* head)
	{
		auto fast = head;
		auto slow = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}
};