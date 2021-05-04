typedef long long int ll;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    
        ll n = nums.size();
        vector<int> cpy;
        cpy = nums;
        bool f= false;
        for(ll i=0;i+1<n;i++){
            if(nums[i]>nums[i+1] && f==false){
                nums[i] = nums[i+1];
                f = true;
            }
        }
        f = false;
        for(ll i=0;i+1<n;i++){
            if(cpy[i]>cpy[i+1] && f==false){
                cpy[i+1] = cpy[i];
                f = true;
            }
        }
        ll c = 1;
        ll c1 = 1;
        for(ll i=0;i+1<n;i++){
            if(nums[i]<=nums[i+1]){
                c++;
            }
        }
        for(ll i=0;i+1<n;i++){
            if(cpy[i]<=cpy[i+1]){
                c1++;
            }
        }
  
        if(c==nums.size() || c1 == nums.size()) return true;
        return false;
    }
};
