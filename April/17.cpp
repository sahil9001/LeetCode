class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int xlen = matrix[0].size(), ylen = matrix.size(), ans = 0;
        unordered_map<int, int> res;
        for (int i = 0; i < ylen; i++)
            for (int j = 1; j < xlen; j++)
                matrix[i][j] += matrix[i][j-1];
        for (int j = 0; j < xlen; j++)
            for (int k = j; k < xlen; k++) {
                res.clear();
                res[0] = 1;
                int csum = 0;
                for (int i = 0; i < ylen; i++) {
                    csum += matrix[i][k] - (j ? matrix[i][j-1] : 0);
                    ans += res.find(csum - target) != res.end() ? res[csum - target] : 0;
                    res[csum]++;
                }
            }
        return ans;
    }
};
