#include <string>
#include <vector>

using namespace std;

int answer = 0;
void DFS(vector<int> numbers, int target, int sum, int count)
{
  //최대깊이 도달
	if (count == numbers.size()) //마지막까지 순회했을 때(다 계산했을 때)
  {
		if (sum == target)  //target값이면 증가
			answer++;
		return;
	}
  
  //최대깊이 도달 전
	DFS(numbers, target, sum + numbers[count], count + 1);  //더하고
	DFS(numbers, target, sum - numbers[count], count + 1);  //빼고
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, target, 0, 0);

	return answer;
}
