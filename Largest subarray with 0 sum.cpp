// better

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int maxLen = 0, sum = 0;
        unordered_map<int, int> sumIndexMap;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxLen = i + 1;
            }
            else if (sumIndexMap.find(sum) != sumIndexMap.end())
            {
                maxLen = max(maxLen, i - sumIndexMap[sum]);
            }
            else
            {
                sumIndexMap[sum] = i;
            }
        }
        return maxLen;
    }
};

// brute force - will Give TLE

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0, currlength = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                currlength = j - i + 1;
                if (sum == 0)
                {
                    ans = max(currlength, ans);
                }
            }
        }
        return ans;
    }
};

