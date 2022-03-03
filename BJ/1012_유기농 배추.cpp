#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 52

int DFS(int x, int y, int matrix[MAX][MAX], bool isvisited[MAX][MAX])
{
	if (isvisited[x][y])
		return 1;
	
	isvisited[x][y] = true;

	if (matrix[x - 1][y])
		DFS(x - 1, y, matrix, isvisited);
	if (matrix[x + 1][y])
		DFS(x + 1, y, matrix, isvisited);
	if (matrix[x][y + 1])
		DFS(x, y + 1, matrix, isvisited);
	if (matrix[x][y - 1])
		DFS(x, y - 1, matrix, isvisited);
	return 1;
}
int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int M, N, K;
		int matrix[MAX][MAX] = { 0, };
		bool isvisited[MAX][MAX] = { false, };

		scanf("%d", &M);
		scanf("%d", &N);
		scanf("%d", &K);

		while (K--)
		{
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			matrix[x + 1][y + 1] = 1;
		}

		int cnt = 0;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				if (!isvisited[i][j] && matrix[i][j] == 1)
					cnt += DFS(i, j, matrix, isvisited);

		printf("%d\n", cnt);
	}

	return 0;
}
