class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> st;
        for (auto x : candyType)
        {
            st.insert(x);
        }
        int allowed = candyType.size() / 2;
        if (allowed <= st.size())
            return allowed;

        return st.size();
    }
};