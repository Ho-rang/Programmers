#include "pch.h"

class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		if (num.length() == k)
			return "0";

		string result;
		vector<char> stack;

		for (int i = 0; i < num.length(); ++i)
		{
			while (k > 0 && !stack.empty() && stack.back() > num[i])
			{
				stack.pop_back();
				--k;
			}
			stack.push_back(num[i]);
		}

		while (k-- > 0)
			stack.pop_back();

		for (char c : stack)
		{
			if (c == '0' && result.empty())
				continue;
			result += c;
		}

		return result.empty() ? "0" : result;
	}
};