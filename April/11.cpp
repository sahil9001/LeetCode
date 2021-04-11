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
class Solution {
    private:
        unordered_map<int,int> mp;
public:
    void trav(TreeNode* root,int l){
        if(!root) return;
        mp[l] += root->val;
        trav(root->left,l+1);
        trav(root->right,l+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        trav(root,0);
        return mp[mp.size()-1];
    }
};
