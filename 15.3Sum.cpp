
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &numbers)
    {
        sort(numbers.begin(), numbers.end());

        vector<vector<int>> result;

        for (int k = 0; k < numbers.size(); k++)
        {

            int target = -numbers[k];
            int i = k + 1;
            int j = numbers.size() - 1;

            // so the i and j values are fixed before moving k as when k proceeds further
            // remains behind and duplicates are handled and when k iterates duplicates are
            // avoided

            while (k + 1 < numbers.size() && numbers[k + 1] == numbers[k])
                k++;

            while (i < j)
            {

                if (numbers[i] + numbers[j] < target)
                    i++;
                else if (numbers[i] + numbers[j] > target)
                    j--;
                else
                {
                    vector<int> triplet = {numbers[k], numbers[i], numbers[j]};
                    result.push_back(triplet);

                    while (i < j && (numbers[i] == triplet[1]))
                        i++;

                    while (i < j && (numbers[j] == triplet[2]))
                        j--;
                }
            }
        }
        return result;
    }
};