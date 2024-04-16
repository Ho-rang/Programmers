#include "pch.h"

class Solution
{
public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth)
	{
		if (depth == 1)
		{
			TreeNode* newRoot = new TreeNode(val, root, nullptr);
			return newRoot;
		}

		queue<pair<TreeNode*, int>> q;
		q.push({ root, 1 });

		while (!q.empty())
		{
			auto [node, d] = q.front();
			q.pop();

			if (node == nullptr)
				continue;

			if (d < depth - 1)
			{
				q.push({ node->left,d + 1 });
				q.push({ node->right,d + 1 });
				continue;
			}

			TreeNode* left = new TreeNode(val, node->left, nullptr);
			TreeNode* right = new TreeNode(val, nullptr, node->right);

			node->left = left;
			node->right = right;
		}

		return root;
	}
};