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
    void addVal(TreeNode *root, int val, int level, int depth)
    {
        if (!root)
            return;

        else if (level == depth - 1)
        {
            cout << level << " " << depth << endl;
            cout << root->val << endl;

            if (root->left)
            {
                TreeNode *newnode = new TreeNode(val);
                TreeNode *prev = root->left;
                root->left = newnode;
                newnode->left = prev;
            }

            if (root->right)
            {
                TreeNode *newnode = new TreeNode(val);
                TreeNode *prev = root->right;
                root->right = newnode;
                newnode->right = prev;
            }
            if (!root->right)
            {
                TreeNode *newnode = new TreeNode(val);
                root->right = newnode;
            }
            if (!root->left)
            {
                TreeNode *newnode = new TreeNode(val);
                root->left = newnode;
            }
            return;
        }
        else
        {
            addVal(root->right, val, level + 1, depth);
            addVal(root->left, val, level + 1, depth);
        }
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newnode = new TreeNode(val);
            TreeNode *prev = root;
            newnode->left = prev;
            root = newnode;
        }
        else
            addVal(root, val, 1, depth);
        cout << root->val << endl;
        return root;
    }
};