class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x/2;
        int ans = 0;

        if (x == 1)
            return 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid < x / mid) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        double i = 1, result = 1;
        while (result <= x)
        {
            i++;
            result = i * i;
        }
        return i - 1;
    }
};