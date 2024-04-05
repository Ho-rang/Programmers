#include "pch.h"

class Solution 
{
public:
	string customSortString(string order, string s)
	{
		string result = "";

		unordered_map<char, int> dictionary;

		for (auto& c : s)
			dictionary[c]++;

		for (auto& c : order)
		{
			result += string(dictionary[c], c);
			dictionary[c] = 0;
		}

		for (auto& [c, len] : dictionary)
		{
			if(len > 0)
				result += string(len, c);
		}

		return result;
	}
};