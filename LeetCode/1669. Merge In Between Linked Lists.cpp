#include "pch.h"

class Solution
{
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
	{
		int len = b - a + 1;

		auto start = list1;
		a--;
		while (a--)
			start = start->next;

		auto temp = start->next;

		start->next = list2;

		while (len--)
			temp = temp->next;

		auto end = list2;
		while (end->next != nullptr)
			end = end->next;

		end->next = temp;

		return list1;
	}
};