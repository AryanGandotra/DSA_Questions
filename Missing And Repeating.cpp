// Optimal

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        long long n = arr.size();

        long long sumofFirstNnumbers = (n * (n + 1)) / 2;
        long long sumofSquaresofFirstNnumbers = (n * (n + 1) * (2 * n + 1)) / 6;

        long long sumofArray = 0;
        long long sumofSquaresArray = 0;

        for (int i = 0; i < n; i++)
        {
            sumofArray += arr[i];
            sumofSquaresArray += (long long)arr[i] * arr[i];
        }

        long long xminusy = sumofArray - sumofFirstNnumbers;
        long long second = sumofSquaresArray - sumofSquaresofFirstNnumbers;

        long long xplusy = second / xminusy;

        long long x = (xminusy + xplusy) / 2;
        long long y = xplusy - x;

        return {(int)x, (int)y};
    }
};

// better

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();
        int duplicate = -1, missing = -1;
        vector<int> hash(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                missing = i;
            }
            else if (hash[i] == 2)
            {
                duplicate = i;
            }
        }

        return {duplicate, missing};
    }
};