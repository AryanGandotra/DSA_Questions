class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans, positives, negatives;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                positives.push_back(nums[i]);
            else
                negatives.push_back(nums[i]);
        }

        for (int i = 0; i < positives.size(); i++)
        {
            nums[2 * i] = positives[i];
            nums[2 * i + 1] = negatives[i];
        }

        return nums;
    }
};