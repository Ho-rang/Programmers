#include <vector>
#include <set>

using namespace std;

bool CheckCard(set<int>& card1, set<int>& card2, int targetNum)
{
	for (auto num : card1)
	{
		auto iter = card2.find(targetNum - num);
		if (iter != card2.end())
		{
			card1.erase(num);
			card2.erase(iter);
			return true;
		}
	}

	return false;
}

int solution(int coin, vector<int> cards)
{
	int answer = 1;

	const int targetNum = cards.size() + 1;
	set<int> hand;
	set<int> sub;

	for (int i = 0; i < cards.size() / 3; i++)
		hand.insert(cards[i]);

	for (int index = cards.size() / 3; index < cards.size(); )
	{
		sub.insert(cards[index++]);
		sub.insert(cards[index++]);

		if (CheckCard(hand, hand, targetNum))
		{

		}
		else if (coin >= 1 && CheckCard(hand, sub, targetNum))
		{
			coin -= 1;
		}
		else if (coin >= 2 && CheckCard(sub, sub, targetNum))
		{
			coin -= 2;
		}
		else
		{
			break;
		}


		answer++;
	}

	return answer;
}