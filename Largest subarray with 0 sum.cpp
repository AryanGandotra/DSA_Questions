// brute force - will Give TLE

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int ans = 0, sum = 0;
        map<int, int> hashmap;

        for (int i = 0; i < arr.size(); i++)
        {
            int currlength = 0;
            sum += arr[i];
            if (hashmap.find(-sum) != hashmap.end())
            {
                currlength = i + 1;
                ans = max(currlength, ans);
            }
        }
        return ans;
    }
};