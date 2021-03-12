class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = (nums.size() * (nums.size() + 1)) / 2;
        int sum1 = 0;
        for (auto x : nums)
            sum1 += x;
        return sum - sum1;
    }
};