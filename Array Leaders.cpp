class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        vector<int> ans;
        int maxElementOnRight = arr[arr.size() - 1];
        ans.push_back(maxElementOnRight);

        for (int i = arr.size() - 2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = maxElementOnRight;
            if (maxElementOnRight <= temp)
            {
                ans.insert(ans.begin(), temp);
                maxElementOnRight = temp;
            }
        }
        return ans;
    }
};