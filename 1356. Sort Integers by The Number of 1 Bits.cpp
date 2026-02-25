class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {

        vector<pair<int, int>> vec;

        for (int i = 0; i < arr.size(); i++)
        {
            int binary = 0;
            int num = arr[i];

            while (num > 0)
            {
                binary += (num % 2);
                num /= 2;
            }

            vec.push_back({binary, arr[i]});
        }

        sort(vec.begin(), vec.end());

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = vec[i].second;
        }

        return arr;
    }
};