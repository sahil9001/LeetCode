class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.size();
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            vector<string> tmp;
            int k = 0;
            for(int j=0;j<products.size();j++){
                if(products[j].substr(0,i+1) == searchWord.substr(0,i+1) && k<3){
                    tmp.push_back(products[j]);
                    k++;
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
