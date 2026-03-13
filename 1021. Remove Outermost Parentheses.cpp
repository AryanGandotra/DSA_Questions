class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans;
        stack<char> st;
        int i = 0;

        while (i < s.length())
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == '(')
                {
                    st.push(s[i]);
                    ans += s[i];
                }
                else
                {
                    char top = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        ans += s[i];
                    }
                }
            }
            i++;
        }
        return ans;
    }
};