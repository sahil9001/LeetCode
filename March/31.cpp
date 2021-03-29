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
    vector<int> ans;
    int index = 0;
public:
    void dfs(TreeNode* node,vector<int>& voyage){
        if(node!=NULL){
            if(node->val!=voyage[index++]){
                ans.clear();
                ans.push_back(-1);    
                return;
            }
            if(index<voyage.size() && node->left!=NULL && node->left->val != voyage[index]){
                ans.push_back(node->val);
                dfs(node->right,voyage);
                dfs(node->left,voyage);
            }
            else{
                dfs(node->left,voyage);
                dfs(node->right,voyage);
            
            }
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root,voyage);
        if(ans.size()>=1 && ans[0] == -1){
            return {-1};
        }
        return ans;
        
    }
};
