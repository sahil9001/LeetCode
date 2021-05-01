class WordFilter
{
private:
    map<string, int> mp;

public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string curWord = words[i];

            vector<string> prefix;
            vector<string> suffix;

            for (int j = 0; j <= curWord.length(); j++)
            {
                prefix.push_back(curWord.substr(0, j));
                suffix.push_back(curWord.substr(j));
            }

            for (string p : prefix)
            {
                for (string s : suffix)
                {
                    string key = p + "#" + s;

                    if (mp.count(key) == 0)
                    {
                        mp[key] = i;
                    }
                    else
                    {
                        mp[key] = max(mp[key], i);
                    }
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        string s = prefix + "#" + suffix;
        return mp.count(s) != 0 ? mp[s] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */