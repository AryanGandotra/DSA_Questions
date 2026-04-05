// recursive
class Solution
{
public:
    int binarySearch(int low, int high, vector<int> &nums, int target)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target < nums[mid])
        {
            return binarySearch(low, mid - 1, nums, target);
        }
        else
        {
            return binarySearch(mid + 1, high, nums, target);
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        return binarySearch(low, high, nums, target);
    }
};

// iterative
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (nums[mid] != target)
        {
            return -1;
        }

        return mid;
    }
};
