class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < B.size(); i++)
        {
            vp.push_back({B[i], i});
        }
        sort(vp.rbegin(), vp.rend());
        sort(A.rbegin(), A.rend());
        vector<int> ans(A.size());
        int k = 0;
        int i = 0, j = B.size() - 1;
        for (auto x : vp)
            ans[x.second] = A[i] > B[x.second] ? A[i++] : A[j--];
        return ans;
    }
};