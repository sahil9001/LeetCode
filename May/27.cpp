class Solution {
public:
    
    int max(int a, int b){
        return a>b ? a : b;
    }
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> m;
        for(int i=0;i<words.size();i++){
             string s = words[i];
             int key = 0;
             for(int j = 0; j < s.size(); j++){
                key |= 1 << (s[j] - 'a');
             }
             m[i] = key;
        }
        int mx = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((m[i] & m[j]) == 0){
                    mx = max(mx,words[i].size()*words[j].size());
                }
            }
        }
        return mx;
    }
};
