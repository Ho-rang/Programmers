string solution(int n) {
	string answer = "";
	for (int i = 0; i < n; i++) {
		i % 2 == 0 ? answer.append("수") : answer.append("박");
	}
	return answer;
}
