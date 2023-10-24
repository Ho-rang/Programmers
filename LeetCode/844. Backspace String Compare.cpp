#include <string>

using std::string;

class Solution {
public:
	bool backspaceCompare(string s, string t) 
	{
		string s1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != '#')
				s1 += s[i];
			else
				s1.pop_back();
		}
		string t1;
		for (int i = 0; i < t.length(); i++)
		{
			if (t[i] != '#')
				t1 += t[i];
			else
				t1.pop_back();
		}

		return s1 == t1;
	}
};