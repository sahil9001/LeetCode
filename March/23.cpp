class Solution
{
public:
    bool reorderedPowerOf2(int N)
    {
        string s1 = to_string(N);
        sort(s1.begin(), s1.end());
        for (int i = 0; i < 30; i++)
        {
            string s2 = to_string(1 << i);
            sort(s2.begin(), s2.end());
            if (s1 == s2)
                return true;
        }
        return false;
    }
};