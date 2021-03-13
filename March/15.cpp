class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        long long int MOD = 1000000007;
        unordered_map<int, int> dp;
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] += 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                    dp[arr[i]] = ((dp[arr[i]] % MOD) + ((dp[arr[j]] % MOD) * (dp[arr[i] / arr[j]] % MOD)) % MOD) % MOD;
            }
            ans = (ans % MOD + dp[arr[i]] % MOD) % MOD;
        }
        return ans;
    }
};