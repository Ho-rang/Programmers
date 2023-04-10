#include <string>
#include <vector>
#include <algorithm>

int checkWin(std::vector<std::string>& board, char player)
{
	int winCount = 0;
	// 가로
	for (int i = 0; i < 3; i++)
		if (player == board[i][0] && board[i][1] == player && board[i][2] == player)
			winCount++;

	// 세로
	for (int i = 0; i < 3; i++)
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
			winCount++;

	// 대각선
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
		winCount++;

	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
		winCount++;

	return winCount;
}

int solution(std::vector<std::string> board)
{
	int O = 0;
	int X = 0;

	for (auto boa : board)
	{
		for (auto c : boa)
		{
			if (c == 'O')
				O++;
			else if (c == 'X')
				X++;
		}
	}
	if (O < X)
		return 0;
	else if (O - X > 1)
		return 0;
	else if (O + X == 9 && O - X != 1)
		return 0;

	int Owin = checkWin(board, 'O');
	int Xwin = checkWin(board, 'X');

	if (Owin + Xwin > 2)
		return 0;

	if (Xwin > 0)
	{
		if (Owin > 0)
			return 0;

		if (O > X)
			return 0;
	}
	else if(Owin > 0)
	{
		if (!(O - X == 1))
			return 0;
	}

	return 1;
}

void main()
{
	solution({ "O.X", ".O.", "..X" });
}