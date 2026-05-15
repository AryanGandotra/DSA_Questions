class Solution
{
public:
    bool canPlace(vector<int> &stalls, int cows, int dist)
    {
        int cowCnt = 1, lastPosition = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastPosition >= dist)
            {
                cowCnt++;
                lastPosition = stalls[i];
            }
        }

        if (cowCnt >= cows)
            return true;
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[stalls.size() - 1] - stalls[0];
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canPlace(stalls, k, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};