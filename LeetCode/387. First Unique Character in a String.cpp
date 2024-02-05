#include <string>
#include <vector>

class Solution
{
public:
	int firstUniqChar(std::string s)
	{
		int alphabet[26] = { 0 };

		for (int i = 0; i < s.length(); i++)
			alphabet[s[i] - 'a']++;

		for (int i = 0; i < s.length(); i++)
			if (alphabet[s[i] - 'a'] == 1)
				return i;

		return -1;
	}
};