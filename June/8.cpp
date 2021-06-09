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
        int idx = 0;
        unordered_map<int,int> m;
    public:
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int start,int end){
        if(start> end){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[idx++]);
        if(start == end) return node;
        int mid = m[node->val];
        node->left = helper(preorder,inorder,start,mid-1);
        node->right = helper(preorder,inorder,mid + 1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n  = inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder,inorder,0,n-1);
        return root;
    }
};
