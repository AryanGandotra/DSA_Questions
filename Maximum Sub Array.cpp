class Solution
{
public:
    vector<int> findSubarray(vector<int> &arr)
    {

        long long maxSum = -1, sum = 0;
        int ansStart = -1, ansEnd = -1, start = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            if (arr[i] < 0)
            {
                sum = 0;
                start = i + 1;
                continue;
            }

            if (sum == 0)
                start = i;

            sum += arr[i];

            if (sum > maxSum ||
                (sum == maxSum && (i - start > ansEnd - ansStart)))
            {
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }
        }

        if (ansStart == -1)
            return {-1};

        return vector<int>(arr.begin() + ansStart, arr.begin() + ansEnd + 1);
    }
};