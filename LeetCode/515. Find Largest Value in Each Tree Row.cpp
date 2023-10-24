#include <vector>

using std::vector;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
#include <algorithm>

class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        std::vector<int> result;

        std::queue<TreeNode*> q;

        while (!q.empty())
        {
            int levelSize = q.size();

            result.push_back(INT_MIN);

            for (int i = 0; i < levelSize; i++)
            {
                auto node = q.front();
                q.pop();

                result.back() = std::max(result.back(),node->val);

                if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
            }
            
        }

        return result;
    }
};