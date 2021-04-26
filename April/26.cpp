typedef long long int ll;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
          int ans = 0;
        long long totsum = 0;
        long long maxsum = 0; 
        multiset<int> store;
 
        for(int i=1;i<heights.size();i++)
        {
            if(heights[i]<=heights[i-1])
            {
                ans = i;
                continue;
            }
 
            int diff = heights[i] - heights[i-1];
 
            if(store.size()<ladders)
            {
                maxsum+=diff;
                store.insert(diff);
            }
            else
            {
        
                if(!store.empty() and diff>*store.begin())
                {
                    maxsum-=(*store.begin());
                    store.erase(store.begin());
                    store.insert(diff);
                    maxsum+=diff;
                }
            }
 
            totsum+=diff;
            if(bricks>=totsum-maxsum)
                ans = i;
            else
                break;
        }
 
        return ans;
    }
};
