class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vp;
        for(int i=0;i<speed.size();i++){
            vp.push_back({efficiency[i],speed[i]});
        }
        sort(vp.begin(),vp.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first > b.first;
        });
        priority_queue<int,vector<int>,greater<int>> minHeap;
        long long int sum = 0;
        long long int ans = 0;
        for(auto &[x,y]:vp){
            sum += y;
            minHeap.emplace(y);
            if(minHeap.size()>k){
                sum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans,sum*x);
        }
        long long int mod = 1e9 + 7;
        return ans%mod;
    }
};
