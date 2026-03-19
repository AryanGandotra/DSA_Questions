class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = INT_MIN, n = s.length();

        if (n == 0)
            return n;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(256, 0);
            for (int j = i; j < n; j++)
            {
                if (freq[s[j]] == 0)
                {
                    freq[s[j]]++;
                    ans = max(ans, j - i + 1);
                }
                else
                    break;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int currLength = 0, maxLength = 0;
        map<char, int> mp;
        int i = 0, j = 0;

        while (j < s.length())
        {
            if (mp.find(s[j]) != mp.end())
            {
                i = max(i, mp[s[j]] + 1);
            }

            mp[s[j]] = j;
            currLength = j - i + 1;
            maxLength = max(maxLength, currLength);
            j++;
        }

        return maxLength;
    }
};