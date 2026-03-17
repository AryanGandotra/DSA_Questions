class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty() && s[i] == '(')
            {
                st.push(s[i]);
                ans = max(ans, (int)st.size());
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
                ans = max(ans, (int)st.size());
            }
            else if (s[i] == ')' && !st.empty())
            {
                st.pop();
            }
        }
        return ans;
    }
};