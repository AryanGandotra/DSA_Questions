class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return (ans == -1) ? nums.size() : ans;
    }
};

// brute force - linear search

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size(), ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
                return i;
            else if (nums[i] > target)
            {
                ans = i;
                break;
            }
        }
        return (ans == -1) ? n : ans;
    }
};