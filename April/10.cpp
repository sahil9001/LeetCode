class Solution
{
public:
    int dp[201][201];
    int dfs(vector<vector<int>> &matrix, int curr, int i, int j)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= curr)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int p = matrix[i][j];
        matrix[i][j] = -1;
        int max1 = max(dfs(matrix, p, i + 1, j), dfs(matrix, p, i - 1, j));
        int max2 = max(dfs(matrix, p, i, j - 1), dfs(matrix, p, i, j + 1));
        matrix[i][j] = p;
        return dp[i][j] = 1 + max(max1, max2);
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        memset(dp, -1, sizeof dp);
        int f = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                f = max(f, dfs(matrix, -1, i, j));
            }
        }
        return f;
    }
};