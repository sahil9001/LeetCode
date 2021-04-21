class Solution {
public:
    int dp[201][201];
    int calc(int row,int col, vector<vector<int>>& matrix){
        if(row>=matrix.size()){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        if(col<matrix[row].size())
            dp[row][col] =  min(matrix[row][col]+calc(row+1,col,matrix),matrix[row][col]+calc(row+1,col+1,matrix));
        return dp[row][col];
    }
    int recurs(int i,vector<vector<int>>& matrix){
        return calc(0,i,matrix);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        memset(dp,-1,sizeof dp);
        return calc(0,0,triangle);
    }
};
