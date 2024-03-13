#include "pch.h"

class Solution
{
public:
	int pivotInteger(int n)
	{
		const int total = (n * (n + 1)) / 2;
		for (int pivot = n; pivot > 0; pivot--)
		{
			int left = (pivot * (pivot + 1)) / 2;
			int right = total - left + pivot;

			if (left == right)
				return pivot;
			else if (left < right)
				break;
		}

		return -1;
	}
};