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
    
public:
    void trav(TreeNode* root,int level,vector<vector<int>>& v){
        if(!root) return;
        v[level].push_back(root->val);
        trav(root->left,level + 1,v);
        trav(root->right,level + 1,v);
        return;
    }
    int maxheight(TreeNode* root){
        if(!root) return 0;
        return 1 + max(maxheight(root->left),maxheight(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = maxheight(root);
        vector<vector<int>> v(h);
        trav(root,0,v);
        return v;
    }
};
