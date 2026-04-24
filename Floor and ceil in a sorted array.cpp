class Solution
{
public:
    int findFloor(const vector<int> &arr, int x)
    {
        int low = 0, high = arr.size() - 1, floor = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
            {
                floor = arr[mid]; // This is a candidate for floor
                low = mid + 1;    // Try to find a larger value
            }
            else
            {
                high = mid - 1;
            }
        }
        return floor;
    }

    int findCeil(const vector<int> &arr, int x)
    {
        int low = 0, high = arr.size() - 1, ceil = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                ceil = arr[mid]; // This is a candidate for ceil
                high = mid - 1;  // Try to find a smaller value
            }
            else
            {
                low = mid + 1;
            }
        }
        return ceil;
    }

    pair<int, int> findFloorCeil(const vector<int> &arr, int x)
    {
        return {findFloor(arr, x), findCeil(arr, x)};
    }
};