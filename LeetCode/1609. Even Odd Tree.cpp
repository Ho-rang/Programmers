
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <queue>

class Solution
{
public:
	bool isEvenOddTree(TreeNode* root)
	{
		struct Data
		{
			int level;
			TreeNode* node;
		};
		std::queue<Data> bfs;

		bfs.push({ 0,root });

		int lastLevel = -1;
		int lastNum = 0;

		while (!bfs.empty())
		{
			auto [level, node] = bfs.front();
			bfs.pop();

			if (node->left)		bfs.push({ level + 1,node->left });
			if (node->right)	bfs.push({ level + 1,node->right });

			if (lastLevel != level)
			{
				lastLevel = level;
				if (level & 1)
					lastNum = INT_MAX;
				else
					lastNum = 0;
			}

			// È¦¼ö
			if (level & 1)
			{
				if (node->val & 1 || lastNum <= node->val)
					return false;
			}
			// Â¦¼ö
			else
			{
				if ((node->val & 1) == 0 || lastNum >= node->val)
					return false;
			}

			lastNum = node->val;
		}

		return true;
	}
};