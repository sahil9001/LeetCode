class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        if(nums.size()==0) return 0;
        int i=1;
        int len = 1;
        int mx = 1;
        while(i<nums.size()){
            if(nums[i-1]+1 == nums[i]){
                len++;
            }
            else{
                len = 1;
            }
            mx = max(mx,len);
            i++;
        }
        return mx;
    }
};
