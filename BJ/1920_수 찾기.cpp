#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
	int N;
	int temp;

	scanf("%d", &N);

	std::vector<int> A;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		A.push_back(temp);
	}
	sort(A.begin(), A.end());
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (std::binary_search(A.begin(), A.end(), temp))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}