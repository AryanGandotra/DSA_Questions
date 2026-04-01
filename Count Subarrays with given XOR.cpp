// brute force - will give TLE

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        int ans = 0, runningxor = 0, n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                runningxor = runningxor ^ arr[j];

                if (runningxor == k)
                {
                    ans++;
                }
            }
            runningxor = 0;
        }

        return ans;
    }
};
