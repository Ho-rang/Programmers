#include "pch.h"

class Solution
{
public:
	int minOperations(vector<int>& nums, int k)
	{
		auto result = 0;

		auto xorValue = 0;

		for (auto n : nums)
			xorValue ^= n;

		constexpr auto bits = sizeof(int) * 8;
		auto xorValueBit = bitset<bits>(xorValue);
		auto kBit = bitset<bits>(k);

		for (auto i = 0; i < bits; i++)
			result += xorValueBit[i] != kBit[i];

		return result;
	}
};