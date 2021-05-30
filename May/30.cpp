class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mn = 0;
        for(int i=0;i+1<nums.size();i++){
            mn = max(mn,nums[i+1]-nums[i]);
        }
        return mn;
    }
};
