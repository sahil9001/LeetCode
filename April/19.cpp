class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = target;
        vector<unsigned int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<n+1;i++){
            for(auto x:nums){
                if(i-x>=0){
                    dp[i] += dp[i-x];
                }
            }
        }
        
        return dp[n];
    }
};