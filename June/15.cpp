class Solution {
public:
    bool subsetsum(vector<int>& arr){
        int sum = 0;
        for(auto x:arr) sum+=x;
        if(sum%2==1) return false;
        else{
            int n = arr.size();
            int m = sum/2;
            bool dp[arr.size() + 1][sum/2 + 1];
            for(int i=0;i<=arr.size();i++){
                dp[i][0] = true;
            }
            for(int i=0;i<=m;i++){
                dp[0][i] = false;
            }
            dp[0][0] = true;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(j>=arr[i-1]){
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][m];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int k = matchsticks.size();
        int ss = 0;
        for(auto x:matchsticks) ss += x;
        if(ss%4!=0) return false;
        for(int i=0;i<(1<<k);i++){
            vector<int> arr;
            vector<int> arr1;
            
            int sum1 = 0,sum2 = 0;
            for(int j=0;j<k;j++){
                if(i & (1<<j)){
                    arr.push_back(matchsticks[j]);
                    sum1 += matchsticks[j];
                    
                }
                else{
                    arr1.push_back(matchsticks[j]);
                    sum2 += matchsticks[j];
                }
            }
            if(sum1 == sum2 && subsetsum(arr) && subsetsum(arr1)) return true;
        }
        return false;
    }
};
