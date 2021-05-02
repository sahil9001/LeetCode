typedef long long int ll;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
sort(begin(courses), end(courses), [](const auto& v1, const auto& v2) {return v1[1] < v2[1]; });
        multiset<int> processed;
        int days_spent = 0;
        int ans = 0;
        auto process_course = [&](int days_required, int deadline) {
            if (days_spent + days_required <= deadline) {
                days_spent += days_required;
                ++ans;
                processed.insert(days_required);
                return true;
            }
            return false;
        };
        for (const auto& v : courses) {
            if (!process_course(v[0], v[1]) && !empty(processed) && *prev(processed.end()) > v[0]) {
                int max_val = *prev(processed.end());
                processed.erase(prev(processed.end()));
                processed.insert(v[0]);
                days_spent -= (max_val - v[0]);
            }
        }
        return ans;
    }
};
