class Solution {
public:
    unordered_map<string, string> ordered;
    unordered_map<string, unordered_set<string>> existed;
    unordered_map<string, int> pos;
    
    string toLower(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
    void func(string& ans, int& pos2, string input, int ptr){
        if(ptr == input.size()){
            if(ordered.count(input)){
                if(pos[ordered[input]] < pos2){
                    pos2 = pos[ordered[input]];
                    ans = ordered[input];
                }
            }
        }
        else{
            if(input[ptr] == 'a' || input[ptr] == 'e' || input[ptr] == 'i' || input[ptr] == 'o' || input[ptr] == 'u'){
                input[ptr] = 'a';
                func(ans, pos2, input, ptr+1);
                input[ptr] = 'e';
                func(ans, pos2, input, ptr+1);
                input[ptr] = 'i';
                func(ans, pos2, input, ptr+1);
                input[ptr] = 'o';
                func(ans, pos2, input, ptr+1);
                input[ptr] = 'u';
                func(ans, pos2, input, ptr+1);
            }
            else func(ans, pos2, input, ptr+1);
        }
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        
        for(int i=0; i<wordlist.size(); i++){
            if(pos.count(wordlist[i]) == 0)pos[wordlist[i]] = i;
            string toL = toLower(wordlist[i]);
            if(existed.count(toL) == 0){

                existed[toL].insert(wordlist[i]);
                ordered[toL] = wordlist[i];
            }
            else{
                existed[toL].insert(wordlist[i]);
            }
        }
        vector<string> ret;
        for(int i=0; i<queries.size(); i++){
            string toL = toLower(queries[i]);
            if(existed.count(toL)){
                if(existed[toL].count(queries[i]))ret.push_back(queries[i]);
                else ret.push_back(ordered[toL]);
            }
            else{
                string ans = "";
                int pos2 = INT_MAX;
                func(ans, pos2, toL, 0);
                ret.push_back(ans);
            }
        }
        return ret;
    }
};
