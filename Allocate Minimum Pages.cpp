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

    int getStudents(vector<int> &arr, int mid)
    {
        int students = 1;
        int currSutdentCapacity = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (currSutdentCapacity + arr[i] <= mid)
            {
                currSutdentCapacity += arr[i];
            }
            else
            {
                students++;
                currSutdentCapacity = arr[i];
            }
        }

        return students;
    }

    int findPages(vector<int> &arr, int k)
    {

        if (arr.size() < k)
            return -1;

        int low = getMax(arr);
        int high = getSum(arr);
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int numberOfStudentsOnMid = getStudents(arr, mid);
            if (numberOfStudentsOnMid <= k)
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