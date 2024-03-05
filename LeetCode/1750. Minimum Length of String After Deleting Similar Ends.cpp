#include "pch.h"

class Solution
{
public:
	int minimumLength(string s)
	{
		int front = 0;
		int back = s.length() - 1;

		while (front < back && s[front] == s[back])
		{
			while (true)
			{
				if (front != back && s[front] == s[front + 1])
					front++;
				else if (front != back && s[back] == s[back - 1])
					back--;
				else
					break;
			}

			front++;
			back--;
		}

		if (front > back)
			return 0;
		else
			return back - front + 1;
	}
};