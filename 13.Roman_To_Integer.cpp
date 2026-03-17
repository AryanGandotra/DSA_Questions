class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (roman[s[i]] < roman[s[i + 1]])
            {
                res -= roman[s[i]];
            }
            else
            {
                res += roman[s[i]];
            }
        }

        return res + roman[s.back()];
    }
};

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> table;
        map<char, int>::iterator it;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            it = table.find(s[i]);
            if (it == table.end())
                break;
            else
            {
                if (s[i] == 'I' && s[i + 1] == 'I' && s[i + 2] == 'I' && s[i + 3] == 'I')
                {
                    sum = sum + 4;
                    i = i + 3;
                }
                else if (s[i] == 'I' && s[i + 1] == 'V')
                {
                    sum = sum + 4;
                    i = i + 1;
                }
                else if (s[i] == 'I' && s[i + 1] == 'X')
                {
                    sum = sum + 9;
                    i = i + 1;
                }
                else if (s[i] == 'X' && s[i + 1] == 'L')
                {
                    sum = sum + 40;
                    i = i + 1;
                }
                else if (s[i] == 'X' && s[i + 1] == 'C')
                {
                    sum = sum + 90;
                    i = i + 1;
                }
                else if (s[i] == 'C' && s[i + 1] == 'D')
                {
                    sum = sum + 400;
                    i = i + 1;
                }
                else if (s[i] == 'C' && s[i + 1] == 'M')
                {
                    sum = sum + 900;
                    i = i + 1;
                }
                else
                {
                    sum = sum + it->second;
                }
            }
        }
        return sum;
    }
};