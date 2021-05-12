class NumMatrix {
    private:
        vector<vector<int>> mt;
        vector<vector<int>> pref;
    public:
    NumMatrix(vector<vector<int>>& matrix) {
            for(auto x:matrix){
                vector<int> ans;
                vector<int> p;
                int sum = 0;
                for(auto y:x){
                    ans.push_back(y);
                    sum += y;
                    p.push_back(sum);
                }
                pref.push_back(p);
                mt.push_back(ans);
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        // for(auto x:pref){
        //     for(auto y:x) cout << y << " ";
        //     cout << endl;
        // }
        for(int i=row1;i<=row2;i++){
                sum += (pref[i][col2]-pref[i][col1] + mt[i][col1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
