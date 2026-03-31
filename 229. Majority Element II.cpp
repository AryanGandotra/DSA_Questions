//  brute force

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