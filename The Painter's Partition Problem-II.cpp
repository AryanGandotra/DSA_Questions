class Solution
{
public:
    int getSum(vector<int> &arr)
    {
        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
        }
        return ans;
    }

    int getMax(vector<int> &arr)
    {
        int ans = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            ans = max(ans, arr[i]);
        }
        return ans;
    }

    int getPainters(vector<int> &arr, int mid)
    {
        int painters = 1;
        int currPaintersCapacity = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (currPaintersCapacity + arr[i] <= mid)
            {
                currPaintersCapacity += arr[i];
            }
            else
            {
                painters++;
                currPaintersCapacity = arr[i];
            }
        }

        return painters;
    }

    int minTime(vector<int> &arr, int k)
    {
        int low = getMax(arr);
        int high = getSum(arr);
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int numberOfPainters = getPainters(arr, mid);
            if (numberOfPainters <= k)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};