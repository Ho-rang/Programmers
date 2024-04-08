#include "pch.h"

class Solution
{
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches)
	{
		int zeroCount = ranges::count(students, 0);
		auto count = make_pair(zeroCount, students.size() - zeroCount);

		for (auto sandwich : sandwiches)
		{
			auto& [zero, one] = count;

			if (sandwich == 0)
			{
				if (zero-- == 0)
					return one;
			}
			else
			{
				if (one-- == 0)
					return zero;
			}
		}

		return 0;
	}
};