class Solution {
public:
    int countBinarySubstrings(string S) {
    int ans = 0;
    int i = 0;
    int n = S.size();
    while (i < n) {
        int cnt0 = 0, cnt1 = 0;
        if (S[i] == '0') {
            while (i < n && S[i] == '0') {
                cnt0++;
                i++;
            }
            int j = i;
            while (j < n && S[j] == '1') {
                cnt1++;
                j++;
            }
        }
        else {
            while (i < n && S[i] == '1') {
                cnt1++;
                i++;
            }
            int j = i;
            while (j < n && S[j] == '0') {
                cnt0++;
                j++;
            }
        }
        ans += min(cnt0, cnt1);
    }
    return ans;
    }
};
