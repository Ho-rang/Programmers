/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
#include <queue>
#include <algorithm>


class Solution
{
private:
	std::vector<long long> sum;

public:
	long long kthLargestLevelSum(TreeNode* root, int k);

private:
	void TreeSum(TreeNode* node, long long depth = 0);
	
};

long long Solution::kthLargestLevelSum(TreeNode* root, int k)
{
	TreeSum(root);

	std::sort(sum.begin(), sum.end(), std::greater<long long>());
	
	return sum[k - 1];
}

void Solution::TreeSum(TreeNode* node, long long depth)
{
	if (node == nullptr)
		return;

	if (sum.size() == depth)
		sum.push_back(0);

	sum[depth++] += node->val;

	TreeSum(node->left, depth);
	TreeSum(node->right, depth);
}
