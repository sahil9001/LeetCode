class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int mx = -1;
        int total = 0;
        for(int l = 0,r = 0; r<nums.size();r++){
            mp[nums[r]]++;
            total += nums[r];
            while(mp[nums[r]]>1){
                mp[nums[l]]--;
                total -= nums[l++];
            }
            mx = max(mx,total);
        }
        return mx;
    }
};
