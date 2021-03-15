class Solution
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        int cnt = 0;
        int idx = 0;

        string ans = "";
        for (int i = 0; i < longUrl.size(); i++)
        {
            ans += (longUrl[i] + 3);
        }
        return "http://tinyurl.com/" + ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < shortUrl.size(); i++)
        {
            if (shortUrl[i] == '/')
                cnt++;
            if (cnt == 3)
            {
                idx = i + 1;
                break;
            }
        }
        string ans = "";
        for (int i = idx; i < shortUrl.size(); i++)
        {
            ans += (shortUrl[i] - 3);
        }
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));