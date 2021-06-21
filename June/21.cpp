class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows==1){
            return {{1}};
        }
        if(numRows==2){
            v.push_back({1});
            v.push_back({1,1});
            return v;
        }
            v.push_back({1});
            v.push_back({1,1});
        
        for(int i=2;i<numRows;i++){
            vector<int> ans(i+1);
            ans[0] = 1;
            ans[i] = 1;
            int k = 1;
            for(int j=0;j+1<v[i-1].size();j++){
                ans[k] = v[i-1][j] + v[i-1][j+1];
                k++;
            }
            v.push_back(ans);
        }
        return v;
    }
};
