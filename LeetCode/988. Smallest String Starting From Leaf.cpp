#include "pch.h"

class Solution
{
public:
	string smallestFromLeaf(TreeNode* root)
	{
		string result = "";
		string str = "";

		dfs(root, str, result);

		return result;
	}

private:
	void dfs(TreeNode* node, string& str, string& result)
	{
		if (node == nullptr)
			return;

		str.push_back('a' + node->val);

		if (node->left == nullptr && node->right == nullptr)
		{
			if (result.length() == 0)
			{
				result = str;
				ranges::reverse(result.begin(), result.end());
			}
			else
			{
				auto temp = str;
				ranges::reverse(temp.begin(), temp.end());
				result = std::min(result, temp);
			}
		}
		else
		{
			dfs(node->left, str, result);
			dfs(node->right, str, result);
		}

		str.pop_back();
	}
};