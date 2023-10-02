
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#include <string>

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		std::string n = "";

		int flag = 0;
		while (l1 != nullptr || l2 != nullptr || flag == 1)
		{
			int num = flag;
			flag = 0;

			if (l1 != nullptr)
			{
				num += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				num += l2->val;
				l2 = l2->next;
			}

			if (num >= 10)
			{
				num -= 10;
				flag = 1;
			}

			n += (num + '0');
		}

		ListNode* next = nullptr;
		for (int i = n.length() - 1; i >= 0; i--)
		{
			auto node = new ListNode((n[i] - '0'));
			node->next = next;
			next = node;
		}

		return next;
	}
};

int main()
{
	int num = 123456789;
	int reversed = 0;

	while (num != 0)
	{
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}
}