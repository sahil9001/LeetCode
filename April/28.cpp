class Solution {
    private:
        vector<int> v;
    public:
        int calcdp(vector<vector<int>>& obstacleGrid){
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            int dp[m+1][n+1];
            dp[0][0] = 1;
            for(int i=1;i<n;i++){
                if(obstacleGrid[0][i]!=1){
                    dp[0][i] = dp[0][i-1];
                }
                else{
                    dp[0][i] = 0;
                }
            }
            for(int i=1;i<m;i++){
                if(obstacleGrid[i][0]!=1){
                    dp[i][0] = dp[i-1][0];
                }
                else{
                    dp[i][0] = 0;
                }
            }
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(obstacleGrid[i][j]==0){
                        dp[i][j] = dp[i][j-1] + dp[i-1][j];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
            return dp[m-1][n-1];
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if(obstacleGrid[0][0]==1) return 0;
            return calcdp(obstacleGrid);
        }
};
