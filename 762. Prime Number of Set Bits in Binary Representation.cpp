class Solution
{
public:
    int getSetBitCount(int i)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += (i % 2);
            i = i / 2;
        }
        return ans;
    }

    int countPrimeSetBits(int left, int right)
    {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;

        for (int i = left; i <= right; i++)
        {
            if (primes.count(getSetBitCount(i)))
                ans++;
        }

        return ans;
    }
};