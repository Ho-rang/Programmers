#include "pch.h"

class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		_word = word;

		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (Dfs(i, j, board, 0))
					return true;

		return false;
	}

private:
	bool Dfs(int y, int x, vector<vector<char>>& board, int index)
	{
		if (index == _word.size())
			return true;

		if (y < 0 || x < 0 ||
			y >= board.size() || x >= board[0].size() ||
			board[y][x] != _word[index])
			return false;

		board[y][x] -= 26;

		bool temp =
			Dfs(y + 1, x, board, index + 1) ||
			Dfs(y - 1, x, board, index + 1) ||
			Dfs(y, x + 1, board, index + 1) ||
			Dfs(y, x - 1, board, index + 1);

		board[y][x] += 26;

		return temp;
	}

	string _word;
};