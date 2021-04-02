class Solution
{
public:
    int dp[605][105][105];
    int dpcalc(vector<string> &s, int m, int n, int ind)
    {
        if (ind >= s.size())
            return 0;
        if (m < 0 || n < 0)
            return INT_MIN;
        if (dp[ind][m][n] != -1)
            return dp[ind][m][n];
        string nw = s[ind];
        int zero = 0, one = 0;
        for (auto x : nw)
        {
            if (x == '0')
                zero++;
            else
                one++;
        }
        if (m - zero < 0 || n - one < 0)
        {
            return dp[ind][m][n] = dpcalc(s, m, n, ind + 1);
        }
        else
        {
            return dp[ind][m][n] = max(1 + dpcalc(s, m - zero, n - one, ind + 1), dpcalc(s, m, n, ind + 1));
        }
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memset(dp, -1, sizeof dp);
        return dpcalc(strs, m, n, 0);
    }
};