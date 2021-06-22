class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha(26);
        for(int i=0;i<s.size();i++){
            alpha[s[i]-'a'].push_back(i);
        }
        int cnt = 0;
        for(auto c:words){
            int x = -1;
            bool found = true;
            for(auto z:c){
                auto it = upper_bound(alpha[z-'a'].begin(),alpha[z-'a'].end(),x);
                if(it == alpha[z-'a'].end()) found = false;
                else x = *it;
            }
            if(found) cnt++;
        }
        return cnt;
    }
};
