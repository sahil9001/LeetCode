class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        map<char, vector<char>> mp = {
            {'1', {}},
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };
        vector<string> res;
        if (digits.size() == 4)
        {
            for (int i = 0; i < mp[digits[0]].size(); i++)
            {
                for (int j = 0; j < mp[digits[1]].size(); j++)
                {
                    for (int k = 0; k < mp[digits[2]].size(); k++)
                    {
                        for (int l = 0; l < mp[digits[3]].size(); l++)
                        {
                            string s = "";
                            s += mp[digits[0]][i];
                            s += mp[digits[1]][j];
                            s += mp[digits[2]][k];
                            s += mp[digits[3]][l];
                            res.push_back(s);
                        }
                    }
                }
            }
        }
        else if (digits.size() == 3)
        {
            for (int i = 0; i < mp[digits[0]].size(); i++)
            {
                for (int j = 0; j < mp[digits[1]].size(); j++)
                {
                    for (int k = 0; k < mp[digits[2]].size(); k++)
                    {
                        string s = "";
                        s += mp[digits[0]][i];
                        s += mp[digits[1]][j];
                        s += mp[digits[2]][k];
                        res.push_back(s);
                    }
                }
            }
        }
        else if (digits.size() == 2)
        {
            for (int i = 0; i < mp[digits[0]].size(); i++)
            {
                for (int j = 0; j < mp[digits[1]].size(); j++)
                {
                    string s = "";
                    s += mp[digits[0]][i];
                    s += mp[digits[1]][j];
                    res.push_back(s);
                }
            }
        }
        else if (digits.size() == 1)
        {
            for (int i = 0; i < mp[digits[0]].size(); i++)
            {
                string s = "";
                s += mp[digits[0]][i];
                res.push_back(s);
            }
        }

        return res;
    }
};