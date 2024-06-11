#include "pch.h"

class Solution
{
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
	{
		unordered_map<int, int> dictionary;

		int size = arr2.size();
		for (int i = 0; i < size; i++)
			dictionary[arr2[i]] = size - i + 1;

		std::ranges::sort(arr1, [&](int a, int b)
			{
				if (dictionary[a] == dictionary[b])
					return a < b;

				return dictionary[a] > dictionary[b];
			});

		return arr1;
	}
};