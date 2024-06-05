#include "pch.h"

class Solution
{
public:
	vector<string> commonChars(vector<string>& words)
	{
		vector<string> result;

		vector<vector<int>> charCount(words.size(), vector<int>(26));

		for (int i = 0; i < words.size(); i++)
			for (auto c : words[i])
				charCount[i][c - 'a']++;

		for (int i = 0; i < 26; i++)
		{
			int minCount = INT_MAX;

			for (int j = 0; j < words.size(); j++)
				minCount = std::min(minCount, charCount[j][i]);

			for (int j = 0; j < minCount; j++)
				result.push_back(string(1, 'a' + i));
		}

		return result;
	}
};