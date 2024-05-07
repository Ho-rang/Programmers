#include "pch.h"

class Solution
{
public:
	ListNode* doubleIt(ListNode* head)
	{
		stack<int> s;

		{
			auto node = head;
			while (node != nullptr)
			{
				s.push(node->val);
				node = node->next;
			}
		}


		ListNode* result = nullptr;
		ListNode* node = nullptr;

		int temp = 0;
		while (!s.empty())
		{
			int val = s.top();
			s.pop();

			int sum = val + val + temp;
			temp = sum / 10;
			sum = sum % 10;

			result = new ListNode(sum);
			result->next = node;
			node = result;
		}

		if (temp > 0)
		{
			result = new ListNode(temp);
			result->next = node;
		}

		return result;
	}
};