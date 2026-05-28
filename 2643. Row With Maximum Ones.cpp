class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int ans = -1;
        int maxOnes = -1;

        for (int i = 0; i < mat.size(); i++)
        {
            int currOnes = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                    currOnes++;
            }

            if (currOnes > maxOnes)
            {
                ans = i;
                maxOnes = currOnes;
            }
        }

        return {ans, maxOnes};
    }
};