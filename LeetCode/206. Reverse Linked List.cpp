#include "pch.h"

class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		stack<int> s;

		auto temp = head;
		while (temp)
		{
			s.push(temp->val);
			temp = temp->next;
		}

		temp = head;
		while (temp)
		{
			temp->val = s.top();
			s.pop();
			temp = temp->next;
		}

		return head;
	}
};