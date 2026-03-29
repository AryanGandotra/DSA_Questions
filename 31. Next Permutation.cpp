class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int breakpoint = -1;
        int replacemenet = 0;

        for (int j = nums.size() - 2; j >= 0; j--)
        {
            if (nums[j] < nums[j + 1])
            {
                breakpoint = j;
                break;
            }
        }

        if (breakpoint == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i > breakpoint; i--)
        {
            if (nums[i] > nums[breakpoint])
            {
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }

        reverse(nums.begin() + breakpoint + 1, nums.end());
    }
};