class Solution {
public:
    int dp[1001];
    unordered_map<string, int> indexes;
    int dfs(vector<string> &words, int i) {
        if (dp[i])
            return dp[i];
        int n = words[i].size(), len = 0;
        for (int j = 0; j < n; j++) {
            cout << temp << endl;
            if (indexes.count(temp)) {
                len = max(len, 1 + dfs(words, indexes[temp]));
            }
        }
        return dp[i] = len;
    }
    int longestStrChain(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            indexes[words[i]] = i;
        int maxLen = 0;
        for (int i = 0; i < words.size(); i++)
            maxLen = max(maxLen, dfs(words, i));
        return maxLen + 1;
    }
};
