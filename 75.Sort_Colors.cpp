class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0};

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }

        int index = 0;

        for (int i = 0; i < 3; i++)
        {
            if (count[i] > 0)
                while (count[i] > 0)
                {
                    nums[index] = i;
                    index++;
                    count[i]--;
                }
        }
    }
};