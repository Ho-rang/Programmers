#include <vector>
#include <algorithm>

class Solution
{
public:
	int countNicePairs(std::vector<int>& nums)
	{
		std::vector<int> reverseNums(nums.size());

		for (auto& num : nums)
		{
			num -= ReverseInteger(num);
		}

		std::sort(nums.begin(), nums.end());

		long long result = 0;

		int lastNum = nums[0];
		long long count = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (lastNum == nums[i])
			{
				count++;
			}
			else
			{
				result = (result % 1000000007 + (count * (count - 1)) / 2) % 1000000007;
				lastNum = nums[i];
				count = 1;
			}
		}

		result = (result % 1000000007 + (count * (count - 1)) / 2) % 1000000007;

		return result;
	}

	int ReverseInteger(int num)
	{
		int reversed = 0;

		while (num != 0)
		{
			reversed = (reversed * 10) + (num % 10);
			num /= 10;
		}

		return reversed;
	}
};