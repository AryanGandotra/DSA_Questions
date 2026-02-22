class Solution
{
public:
    void getBinaryRep(int n, vector<int> &binary)
    {
        while (n > 0)
        {
            binary.insert(binary.begin(), n % 2);
            n = n / 2;
        }
    }
    int binaryGap(int n)
    {
        vector<int> binary;
        getBinaryRep(n, binary);

        int ans = 0;
        int prevOne = 0;

        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == 1)
            {
                ans = max(ans, i - prevOne);
                prevOne = i;
            }
        }

        return ans;
    }
};