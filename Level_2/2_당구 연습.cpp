#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int distance(double x1, double y1, double x2, double y2)
{
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

double findShortestPathWithReflection(int m, int n, int x1, int y1, int x2, int y2)
{
	int minDistance = 2147483647;
	if (y1 != y2 && x1 != x2)
	{
		minDistance = std::min(minDistance, distance(x1, y1, x2, 2 * n - y2));
		minDistance = std::min(minDistance, distance(x1, y1, x2, -y2));
		minDistance = std::min(minDistance, distance(x1, y1, 2 * m - x2, y2));
		minDistance = std::min(minDistance, distance(x1, y1, -x2, y2));
	}
	else if (y1 == y2)
	{
		if (x1 - x2 > 0)
			minDistance = std::min(minDistance, distance(x1, y1, 2 * m - x2, y2));
		else
			minDistance = std::min(minDistance, distance(x1, y1, -x2, y2));

		minDistance = std::min(minDistance, distance(x1, y1, x2, 2 * n - y2));
		minDistance = std::min(minDistance, distance(x1, y1, x2, -y2));
	}
	else if (x1 == x2)
	{
		if (y1 - y2 > 0)
			minDistance = std::min(minDistance, distance(x1, y1, x2, 2 * n - y2));
		else
			minDistance = std::min(minDistance, distance(x1, y1, x2, -y2));

		minDistance = std::min(minDistance, distance(x1, y1, 2 * m - x2, y2));
		minDistance = std::min(minDistance, distance(x1, y1, -x2, y2));
	}

	return minDistance;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
	vector<int> answer;

	for (auto ball : balls)
	{
		answer.push_back(findShortestPathWithReflection(m, n, startX, startY, ball[0], ball[1]));
	}

	return answer;
}