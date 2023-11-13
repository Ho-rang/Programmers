#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
	std::string sortVowels(std::string s)
	{
		const char vowels[] = "AEIOUaeiou";
		std::vector<int> count(10);
		std::vector<int> index;

		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case 'A':	count[0]++;	index.push_back(i);		break;
			case 'E':	count[1]++;	index.push_back(i);		break;
			case 'I':	count[2]++;	index.push_back(i);		break;
			case 'O':	count[3]++;	index.push_back(i);		break;
			case 'U':	count[4]++;	index.push_back(i);		break;
			case 'a':	count[5]++;	index.push_back(i);		break;
			case 'e':	count[6]++;	index.push_back(i);		break;
			case 'i':	count[7]++;	index.push_back(i);		break;
			case 'o':	count[8]++;	index.push_back(i);		break;
			case 'u':	count[9]++;	index.push_back(i);		break;
			}
		}

		int i = 0;
		for (const auto& pos : index)
		{
			while (count[i] == 0)
				i++;
			count[i]--;

			s[pos] = vowels[i];
		}

		return s;
	}
};