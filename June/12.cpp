class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        int curr = 0;
        int i = 0;
        int cnt = 0;
        priority_queue<int> pq;
        curr += startFuel;
        while(curr<target){
            cnt++;
            while(i<stations.size() && stations[i][0]<=curr){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) break;
            curr += pq.top();
            pq.pop();
        }
        return curr>=target ? cnt : -1;
    }
};
