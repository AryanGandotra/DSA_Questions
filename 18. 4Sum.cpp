class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<int> hash;
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k];
                    long long fourth = 1LL * target - sum;
                    if (fourth >= INT_MIN && fourth <= INT_MAX)
                    {
                        if (hash.find((int)fourth) != hash.end())
                        {
                            vector<int> temp = {
                                nums[i],
                                nums[j],
                                nums[k],
                                (int)fourth};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                    hash.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};