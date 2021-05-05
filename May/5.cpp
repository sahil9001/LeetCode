class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[0] = 0;
        for(int i=1;i<nums.size();i++) dp[i] = INT_MAX;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                for(int k=1;k<=nums[j];k++){
                    if(j+k<nums.size()){
                        dp[j+k] = min(dp[j]+1,dp[j+k]);
                    }
                }
            }
        }
        
        return dp[nums.size()-1];
    }
};
