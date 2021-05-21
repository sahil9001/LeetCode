class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        for(auto x:words){
            map<char,char> mp;
            for(auto y:pattern){
                mp[y] = '0';
            }
            string nw = "";
            for(int i=0;i<pattern.size();i++){
                bool f = false;
                char c;
                for(auto z:mp){
                    if(z.second==x[i]){
                        f = true;
                        c = z.first;
                        break;
                    }
                }
                if(!f){
                    if(mp[pattern[i]]!='0')
                        nw += x[i];
                    else{
                        mp[pattern[i]] = x[i];
                        nw += pattern[i];
                    }
                }
                else{
                    nw += c;
                }
            }
            if(nw==pattern){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
