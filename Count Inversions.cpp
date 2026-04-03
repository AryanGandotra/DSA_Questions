class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high, int &ans)
    {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
            {
                ans += mid - left + 1;
                temp.push_back(arr[right++]);
            }
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive merge sort function
    void mergeSort(vector<int> &arr, int low, int high, int &ans)
    {
        if (low >= high)
            return;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        mergeSort(arr, low, mid, ans);

        // Recursively sort right half
        mergeSort(arr, mid + 1, high, ans);

        // Merge the two sorted halves
        merge(arr, low, mid, high, ans);
    }

    int inversionCount(vector<int> &arr)
    {
        int ans = 0, n = arr.size();
        mergeSort(arr, 0, n - 1, ans);
        return ans;
    }
};