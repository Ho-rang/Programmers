#include <iostream>
#include <algorithm>
#include <vector>

int main()
{	
	int N;
	
	std::cin >> N;
	std::vector<int> A(N + 1);
	for (int i = 1; i <= N; i++)
		std::cin >> A[i];

	std::vector<int> Acnt(N + 1);

	std::vector<int> dp(1);
	for (int i = 1; i <= N; i++)
	{
		int idx = std::lower_bound(dp.begin(),dp.end(),A[i]) - dp.begin();

		Acnt[i] = idx;

		if (idx >= dp.size())
			dp.push_back(A[i]);
		else
			dp[idx] = A[i];

	}

	std::cout << *std::max_element(Acnt.begin(), Acnt.end()) <<std::endl;
	
	return 0;
}
