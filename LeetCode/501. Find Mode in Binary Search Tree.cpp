
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <map>

class Solution
{
public:
	std::vector<int> findMode(TreeNode* root)
	{
		std::vector<int> result;

		std::map<int, int> m;
		CountNumber(m, root);

		int max = INT_MIN;
		for (auto num : m)
		{
			if (num.second == max)
			{
				result.push_back(num.first);
			}
			else if (num.second > max)
			{
				max = num.second;
				result.clear();
				result.push_back(num.first);
			}
		}

		return result;
	}

	void CountNumber(std::map<int, int>& m, TreeNode* node)
	{
		if (node == nullptr)
			return;

		m[node->val]++;

		CountNumber(m, node->left);
		CountNumber(m, node->right);
	}
};