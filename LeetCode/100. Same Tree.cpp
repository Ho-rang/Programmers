
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
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		std::queue<std::pair<TreeNode*, TreeNode*>> bfs;

		bfs.push({ p,q });

		while (!bfs.empty())
		{
			auto first = bfs.front().first;
			auto second = bfs.front().second;
			bfs.pop();

			if (first == nullptr && second == nullptr)
				continue;
			else if (first == nullptr || second == nullptr)
				return false;
			else if (first->val != second->val)
				return false;

			bfs.push({ first->left,second->left });
			bfs.push({ first->right,second->right });
		}

		return true;
	}
};