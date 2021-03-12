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
class Solution
{
public:
    vector<int> ans;
    void levelorder(TreeNode *root, int level)
    {
        if (!root)
            return;
        if (level == 1)
        {
            ans.push_back(root->val);
            return;
        }
        else
        {
            levelorder(root->left, level - 1);
            levelorder(root->right, level - 1);
        }
    }
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        else
        {
            int lheight = height(root->left);
            int rheight = height(root->right);
            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }
    vector<double> averageOfLevels(TreeNode *root)
    {
        long long int h = height(root);
        vector<double> fans;
        for (int i = 1; i <= h; i++)
        {
            levelorder(root, i);
            double sum1 = 0;
            for (auto x : ans)
            {
                sum1 += x;
            }
            fans.push_back((sum1 * 1.0) / (ans.size() * 1.0));
            ans.clear();
        }
        return fans;
    }
};