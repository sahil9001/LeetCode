class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int curr = 0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(target==nums[i]){
                ans[0] = i;
                ans[1] = i;
                break;
            }
        }
        if(ans[0]!=-1){
        for(int i=ans[0];i<n;i++){
            if(target==nums[i]){
                ans[1] = i;
            }    
        }
        }
        return ans;
    }
};
