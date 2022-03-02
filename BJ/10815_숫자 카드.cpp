#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N;
	std::vector<int> card_list;

	scanf("%d", &N);
	while (N--)
	{
		int temp;
		scanf("%d", &temp);
		card_list.push_back(temp);
	}
	sort(card_list.begin(), card_list.end());
	int M;
	scanf("%d", &M);
	while (M--)
	{
		int temp;
		scanf("%d", &temp);

		bool check = std::binary_search(card_list.begin(), card_list.end(), temp);
		if (check)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}