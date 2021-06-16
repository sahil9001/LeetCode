class Solution {
public:
    set<string> st;
    void gen(int n,int c,int e,string s){
        if(c>n || e<0) return;
        if(n==c && e==0){
            st.insert(s);
            return;
        }
        gen(n,c+1,e+1,s+"(");
        gen(n,c,e-1,s + ")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        gen(n,0,0,"");
        vector<string> ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};
