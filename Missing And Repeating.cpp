class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        int duplicate = -1, missing = -1;
        vector<int> hash(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                missing = i;
            }
            else if (hash[i] == 2)
            {
                duplicate = i;
            }
        }

        return {duplicate, missing};
    }
};