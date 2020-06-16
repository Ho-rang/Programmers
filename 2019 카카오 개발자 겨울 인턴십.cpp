#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	vector<int> select;

	for (int j = 0; j < moves.size(); j++)
	{
		int num = moves[j] - 1;
		for (int i = 0; i < board.size(); i++)
			if (board[i][num] > 0)
			{
				if (!select.empty() && select.back() == board[i][num])
				{
					select.pop_back();
					answer += 2;
				}
				else
				{
					select.push_back(board[i][num]);
				}

				board[i][num] = 0;
				break;
			}
	}

	return answer;
}
