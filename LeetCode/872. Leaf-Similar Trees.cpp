
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

class Solution
{
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2)
	{
		std::vector<int> sequence1;
		SequenceDFS(root1, sequence1);

		std::vector<int> sequence2;
		SequenceDFS(root2, sequence2);

		
		if (sequence1.size() != sequence2.size())
			return false;

		int size = std::max(sequence1.size(), sequence2.size());

		for (int i = 0; i < size; i++)
		{
			if (sequence1[i] != sequence2[i])
				return false;
		}
		
		return true;
	}

public:
	void SequenceDFS(TreeNode* node, std::vector<int>& sequence)
	{
		if (node == nullptr)
			return;

		if (node->left == nullptr && node->right == nullptr)
			sequence.push_back(node->val);

		SequenceDFS(node->left, sequence);
		SequenceDFS(node->right, sequence);
	}
};