#include <string>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	std::string tree2str(TreeNode* root)
	{
		result = "";

		DFSTree(root);

		return result;
	}

	void DFSTree(TreeNode* node)
	{
		result += std::to_string(node->val);

		if (node->left != nullptr)
		{
			result += '(';
			DFSTree(node->left);
			result += ')';
		}

		if (node->right != nullptr && node->left != nullptr)
		{
			result += '(';
			DFSTree(node->right);
			result += ')';
		}
		else if (node->right != nullptr && node->left == nullptr)
		{
			result += "()";
			result += '(';
			DFSTree(node->right);
			result += ')';
		}
	}

private:
	std::string result;
};