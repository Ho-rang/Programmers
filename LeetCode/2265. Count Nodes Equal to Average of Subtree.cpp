
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <utility>

class Solution
{
public:
	int averageOfSubtree(TreeNode* root)
	{
		result = 0;

		DFS(root);

		return result;
	}

	std::pair<int, int> DFS(TreeNode* node)
	{
		if (node == nullptr)
			return { 0, 0 };

		auto leftInfo = DFS(node->left);
		auto rightInfo = DFS(node->right);

		auto thisInfo = std::make_pair(
			leftInfo.first + rightInfo.first + node->val,
			leftInfo.second + rightInfo.second + 1);

		if (thisInfo.first / thisInfo.second == node->val)
			this->result++;

		return thisInfo;
	}

private:
	int result;
};