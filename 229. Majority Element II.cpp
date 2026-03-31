// optimised
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0, element1 = -1, element2 = -1, n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != element2)
            {
                cnt1++;
                element1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != element1)
            {
                cnt2++;
                element2 = nums[i];
            }

            else if (nums[i] == element1)
            {
                cnt1++;
            }
            else if (nums[i] == element2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == element1)
                cnt1++;

            else if (nums[i] == element2)
                cnt2++;
        }

        if (cnt1 > n / 3)
            ans.push_back(element1);
        if (cnt2 > n / 3)
            ans.push_back(element2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

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