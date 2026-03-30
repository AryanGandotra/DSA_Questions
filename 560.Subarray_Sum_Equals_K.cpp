class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int prefixSum = 0;
        int count = 0;
        map<int, int> hashmap;
        hashmap[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            if (hashmap.find(prefixSum - k) != hashmap.end())
            {
                count += hashmap[prefixSum - k];
            }
            hashmap[prefixSum]++;
        }

        return count;
    }
};

// brute force approach

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
};