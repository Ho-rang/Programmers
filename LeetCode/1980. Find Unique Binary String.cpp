#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
	std::string findDifferentBinaryString(std::vector<std::string>& nums)
	{
		std::sort(nums.begin(), nums.end());

		this->Recursive("", nums[0].length());

		std::sort(binaryTree.begin(), binaryTree.end());

		int i = 0;
		for (const auto& num : nums)
		{
			if (num != binaryTree[i])
			{
				return binaryTree[i];
			}
			else
			{
				i++;
			}
		}

		return binaryTree[i];
	}

private:
	void Recursive(std::string s, int n)
	{
		if (n == 0)
		{
			binaryTree.push_back(s);
			return;
		}
		n--;
		Recursive(s + "0", n);
		Recursive(s + "1", n);
	}

	std::vector<std::string> binaryTree;
};