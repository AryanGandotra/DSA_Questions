class Solution
{
public:
    int countSubstring(string s)
    {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(3, 0);
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                if (freq[0] == 1 && freq[1] == 1 && freq[2] == 1)
                    ans++;
            }
        }

        return ans;
    }
};