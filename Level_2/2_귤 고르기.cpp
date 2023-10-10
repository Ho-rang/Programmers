#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine)
{
	int answer = 0;

	std::map<int, int> m;
	for (auto size : tangerine)
		m[size]++;

	std::vector<std::pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {	return a.second > b.second; });

	for (auto count : v)
	{
		if (k <= 0)
			break;
		answer++;

		k -= count.second;
	}

	return answer;
}

int main()
{

	return 0;
}