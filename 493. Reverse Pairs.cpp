class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high, int &ans)
    {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    void count_pairs(vector<int> &arr, int low, int mid, int high, int &ans)
    {
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)arr[i] > 2LL * arr[right])
            {
                right++;
            }
            ans += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int> &arr, int l, int r, int &ans)
    {
        if (l >= r)
            return;

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, ans);
        mergeSort(arr, mid + 1, r, ans);
        count_pairs(arr, l, mid, r, ans);
        merge(arr, l, mid, r, ans);
    }

    int reversePairs(vector<int> &nums)
    {
        int ans = 0, n = nums.size();

        mergeSort(nums, 0, n - 1, ans);

        return ans;
    }
};