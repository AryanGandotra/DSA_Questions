class Solution
{
public:
    int getNumberOfOnes(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return arr.size() - ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int ans = -1;
        int maxOnes = -1;

        for (int i = 0; i < arr.size(); i++)
        {
            int NumberOfOnes = getNumberOfOnes(arr[i]);
            if (NumberOfOnes > maxOnes)
            {
                ans = i;
                maxOnes = NumberOfOnes;
            }
        }

        return maxOnes == 0 ? -1 : ans;
    }
};