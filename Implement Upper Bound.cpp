class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;
        int mid = (low + high) / 2;
        int ans = -1;

        while (low <= high)
        {
            if (arr[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }

        return (ans == -1) ? arr.size() : ans;
    }
};
