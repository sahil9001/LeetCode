class Solution {
public:
    string removeDuplicates(string S, int K) {
        for (int i = 1, count = 1; i < S.size(); i++) {
            count = S[i] == S[i-1] ? count + 1 : 1;
            if (count == K) 
                S = removeDuplicates(S.substr(0, i-K+1) + S.substr(i+1), K);
        }
        return S;
    }
};
