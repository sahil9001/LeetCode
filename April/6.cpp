class Solution {
public:
    int minOperations(int n) {
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (2*i) + 1;
        }
        int op = 0;
        int target = sum/n;
        for(int i=n-1;i>=n/2;i--){
            op += ((2*i + 1)-target);
        }
        return op;
    }
};
