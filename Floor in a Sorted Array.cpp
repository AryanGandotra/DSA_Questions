// optimal

class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        int n = arr.size(), ans = -1;
        int low = 0, high = n - 1;
        int mid = (low + high) / 2;

        while (low <= high)
        {

            if (arr[mid] <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;

            mid = (low + high) / 2;
        }

        return ans;
    }
};

// brute force

class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        int ans = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= x)
            {
                if (arr[ans] <= arr[i])
                {
                    ans = i;
                }
            }
        }

        return ans;
    }
};
