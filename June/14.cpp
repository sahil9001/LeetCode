class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         vector<pair<int,int>> vp;
        for(auto x:boxTypes){
            vp.push_back({x[1],x[0]});
        }
        sort(vp.rbegin(),vp.rend());
        int sum = 0;
        for(int i=0;i<vp.size();i++){
            if(vp[i].second<=truckSize){
                sum += vp[i].second*vp[i].first;
                truckSize -= vp[i].second;
                
            }
            else{
                sum += vp[i].first*truckSize;
                truckSize = 0;
                
            }
        }
        return sum;
    }
};
