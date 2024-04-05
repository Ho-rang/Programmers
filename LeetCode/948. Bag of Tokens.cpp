#include "pch.h"

class Solution
{
public:
	int bagOfTokensScore(vector<int>& tokens, int power)
	{
		ranges::sort(tokens);

		int score{ 0 };
		int hightScore{ 0 };

		int faceUp{ 0 };
		int faceDown = tokens.size() - 1;

		while (faceUp <= faceDown)
		{
			if (tokens[faceUp] <= power)
			{
				hightScore = std::max(++score, hightScore);
				power -= tokens[faceUp++];
			}
			else
			{
				if (score-- <= 0)
					return hightScore;
				power += tokens[faceDown--];
			}
		}

		return hightScore;
	}
};