#include <vector>

class Solution
{
public:
	int numSpecial(std::vector<std::vector<int>>& mat)
	{
		int result = 0;

		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				if (mat[i][j] == 0)
					continue;

				bool flag = false;

				for (int row = 0; row < mat[0].size(); row++)
				{
					if (mat[i][row] == 1 && row != j)
					{
						flag = true;
						break;
					}
				}

				if (flag)
				{
					j = mat[0].size();
					break;
				}

				for (int col = 0; col < mat.size(); col++)
				{
					if (mat[col][j] == 1 && col != i)
					{
						flag = true;
						break;
					}
				}

				if (!flag)
					result++;
				else
					j = mat[0].size();

			}
		}

		return result;
	}
};