#include "pch.h"

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		int sDic[256] = { };
		int tDic[256] = { };

		for (int i = 0; i < s.length(); i++)
		{
			if (sDic[s[i]] != tDic[t[i]])
				return false;
			else
				sDic[s[i]] = tDic[t[i]] = t[i];
		}

		return true;
	}
};