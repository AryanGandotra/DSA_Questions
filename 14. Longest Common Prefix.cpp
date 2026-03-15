class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());

        string firstString = strs[0], lastString = strs[strs.size() - 1];

        int minwordLength = min(firstString.length(), lastString.length());
        string ans = "";

        for (int i = 0; i < minwordLength; i++)
        {
            if (firstString[i] == lastString[i])
                ans += firstString[i];
            else
                break;
        }

        return ans;
    }
};