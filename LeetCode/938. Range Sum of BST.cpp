

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
	int rangeSumBST(TreeNode* root, int low, int high)
	{
		int result = 0;

		DFS(root, result, low, high);

		return result;
	}

	void DFS(TreeNode* node, int& sum, const int low, const int high)
	{
		if (node == nullptr)
			return;

		if (node->val < low)
		{
			DFS(node->right, sum, low, high);
		}
		else if (node->val > high)
		{
			DFS(node->left, sum, low, high);
		}
		else
		{

		}
	}
};