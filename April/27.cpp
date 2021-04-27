class Solution {
public:
    bool isPowerOfThree(int n) {
        long long int c = 0ll;
        long long int k = n;
        while(n>1){
            c++;
            n/=3;
        }
        long long int ans = pow(3ll,c);
        return ans == k;
    }
};
