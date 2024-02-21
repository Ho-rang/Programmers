#include <string>
#include <vector>

class Solution
{
public:
	std::string firstPalindrome(std::vector<std::string>& words)
	{
		for (auto& word : words)
		{
			bool check{ true };
			for (int i{ 0 }; i < word.size() / 2; i++)
			{
				if (word[i] != word[word.size() - i - 1]) { check = false; break; }
			}

			if (check == true)
				return word;
		}

		return "";
	}
};