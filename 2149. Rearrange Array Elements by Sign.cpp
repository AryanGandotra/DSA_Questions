// optimal

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        int posCounter = 0, negCounter = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ans[2 * posCounter] = nums[i];
                posCounter++;
            }
            else
            {
                ans[2 * negCounter + 1] = nums[i];
                negCounter++;
            }
        }

        return ans;
    }
};

// Brute force

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