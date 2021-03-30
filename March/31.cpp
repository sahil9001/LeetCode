<<<<<<< HEAD
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(begin(envelopes), end(envelopes), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
        });
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < envelopes.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                {
                    if (dp[i] < dp[j] + 1)
                        dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
=======
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
>>>>>>> c60ef34ec0277ab9d9c0ad906c8ab2fdd3f6fff4
