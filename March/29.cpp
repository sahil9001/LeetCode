class Solution
{
public:
    bool issame(string s, int i, int j)
    {
        string p = s.substr(i, j - i + 1);
        string nw = p;
        reverse(p.begin(), p.end());
        return p == nw ? true : false;
    }
    int countSubstrings(string s)
    {
        int c = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (issame(s, i, j))
                    c++;
            }
        }
        return c;
    }
};