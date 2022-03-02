#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void DFS(int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	 
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[count] = i;
			DFS(count + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	
	DFS(0);
	return 0;
}
