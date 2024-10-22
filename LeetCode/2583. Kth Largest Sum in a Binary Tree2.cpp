class Solution
{
public:
	long long kthLargestLevelSum(TreeNode* root, int k)
	{
		levelSum.resize(k - 1);
		Dfs(root, 0);

		std::sort(levelSum.begin(), levelSum.end(), std::greater<>());

		if (levelSum.size() < k)
			return -1;

		return levelSum[k - 1];
	}

private:
	void Dfs(TreeNode* node, int n)
	{
		if (levelSum.size() <= n)
			levelSum.push_back(node->val);
		else
			levelSum[n] += node->val;

		if (node->left != nullptr)
			Dfs(node->left, n + 1);
		if (node->right != nullptr)
			Dfs(node->right, n + 1);
	}

	std::vector<long long> levelSum;
};