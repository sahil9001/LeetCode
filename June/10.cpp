class MyCalendar {
private:
    vector<pair<int,int>> vp;
public:
    MyCalendar() {
        vp.clear();
    }
    bool isoverlapping(int start,int end){
        for(int i=0;i<vp.size();i++){
            if((vp[i].first<=start && start<=vp[i].second) || (vp[i].first <=end && end<=vp[i].second)) return true;
            if(start<=vp[i].first && end>=vp[i].second) return true;
        }
        return false;
    }
    bool book(int start, int end) {
        if(isoverlapping(start,end-1)) return false;
        vp.push_back({start,end-1});
        sort(vp.begin(),vp.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
