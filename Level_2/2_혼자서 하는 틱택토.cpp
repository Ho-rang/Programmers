#include <string>
#include <vector>
#include <algorithm>

bool checkWin(std::vector<std::string>& board, char player)
{
	// 가로
	for (int i = 0; i < 3; i++)
		if (player == board[i][0] && board[i][1] == player && board[i][2] == player)
			return true;

	// 세로
	for (int i = 0; i < 3; i++)
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			return true;

	// 대각선
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		return true;

	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return true;

	return false;
}

int solution(std::vector<std::string> board)
{
	int a = 0;
	int b = 0;

	for (auto boa : board)
	{
		for (auto c : boa)
		{
			if (c == 'O')
				a++;
			else if (c == 'X')
				b++;
		}
	}
	if (a < b)
		return 0;

	if (checkWin(board, 'O') && checkWin(board, 'X'))
	{
		return 0;
	}

	return 1;
}

void main()
{
	solution({ "O.X", ".O.", "..X" });
}