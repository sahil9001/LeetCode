class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int md = nums[nums.size()/2];
        int sum = 0;
        for(auto x:nums){
            sum += abs(x-md);
        }
        return sum;
    }
};
