class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = (low+high)/2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if ((mid%2==1 && nums[mid] == nums[mid - 1]) || (mid%2==0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[i] != nums[i + 1])
                    return nums[0];
            } else if (i == nums.size() - 1)
                return nums[i];
            else {
                if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                    return nums[i];
            }
        }

        return -1;
    }
};

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        map<int, int> map1;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = map1.find(nums[i]);
            if (it == map1.end())
            {
                map1.insert(it, pair<int, int>(nums[i], 1));
            }
            else
            {
                it->second++;
            }
        }

        int a;
        map<int, int>::iterator it = map1.begin();

        while (it != map1.end())
        {
            if (it->second == 1)
            {
                a = it->first;
                break;
            }
            it++;
        }
        return a;
    }
};