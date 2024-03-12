#include "pch.h"

class Solution
{
public:
	ListNode* removeZeroSumSublists(ListNode* head)
	{
		vector<int> nums;

		while (head != nullptr)
		{
			if (head->val != 0)
				nums.push_back(head->val);
			head = head->next;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0;
			for (int j = i; j < nums.size(); j++)
			{
				sum += nums[j];
				if (sum == 0)
				{
					for (int k = i; k <= j; k++)
						nums[k] = 0;

					i = j;
					break;
				}
			}
		}

		ListNode* node = new ListNode(0);
		ListNode* result = node;

		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 0)
				continue;

			node->next = new ListNode(nums[i]);
			node = node->next;
		}
		node->next = nullptr;

		return result->next;
	}
};