class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> mp(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int save = 0, num = 0;
        vector<int> v;
        for (int i = 1; i < mp.size(); i++)
        {
            if (mp[i] == 0)
                save = i;
            else if (mp[i] == 2)
                num = i;
        }
        v.push_back(num);
        v.push_back(save);
        return v;
    }
};