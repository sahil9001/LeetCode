class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int> mp = {
            {'A',1},
            {'E',1},
            {'I',1},
            {'O',1},
            {'U',1},
            {'a',1},
            {'e',1},
            {'i',1},
            {'o',1},
            {'u',1},       
        };
        int f = 0;
        for(int i=0;i<s.size()/2;i++){
            if(mp[s[i]]>0) f++;
        }
        for(int i=s.size()/2;i<s.size();i++){
            if(mp[s[i]]>0) f--;
        }
        if(!f) return true;
        return false;
    }
};
