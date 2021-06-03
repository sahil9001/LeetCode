class Solution {
public:
    long long int max(long long int a,long long int b){
        return b>a ? b : a;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int mod = 1e9 + 7;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long int mx = horizontalCuts[0];
        for(int i=0;i+1<horizontalCuts.size();i++){
            mx = max(mx,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        mx = max(mx,h-horizontalCuts[horizontalCuts.size()-1]);
        long long int wx = verticalCuts[0];
        for(int i=0;i+1<verticalCuts.size();i++){
            wx = max(wx,verticalCuts[i+1]-verticalCuts[i]);
        }
        wx = max(wx,w-verticalCuts[verticalCuts.size()-1]);
        return ((mx%mod)*(wx%mod))%mod ;
    }
};
