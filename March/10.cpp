class Solution
{
public:
    bool ispalindrome(string s)
    {
        string s1 = s;
        string cmp = s;
        reverse(cmp.begin(), cmp.end());
        return s1 == cmp;
    }

    int removePalindromeSub(string s)
    {
        if (ispalindrome(s))
            return 1;
        return 2;
    }
};