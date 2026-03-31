// better

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> hashmap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            hashmap[nums[i]]++;
        }

        vector<int> ans;

        for (auto element : hashmap)
        {
            if (element.second > (n / 3))
                ans.push_back(element.first);
        }

        return ans;
    }
};

//  brute force

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == nums[i])
                    count++;
                if (count > (n / 3))
                {
                    if (find(ans.begin(), ans.end(), nums[i]) == ans.end())
                    {
                        ans.push_back(nums[i]);
                    }
                    break;
                }
            }
        }

        return ans;
    }
};