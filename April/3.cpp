class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.length() <= 1)
            return 0;
        int curMax = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                curMax = max(dp[i], curMax);
            }
        }
        return curMax;
    }
};