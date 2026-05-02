class Solution {
    public: int countRotations(const vector < int > & nums) {
        int n = nums.size();
        int low = 0, high = n - 1, min_val_index = -1, min_val = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid]) {
                if (nums[low] < min_val) {
                    min_val = nums[low];
                    min_val_index = low;

                }
                low = mid + 1;
            } else {
                if (nums[mid] < min_val) {
                    min_val = nums[mid];
                    min_val_index = mid;

                }
                high = mid - 1;
            }
        }

        return min_val_index % n;

    }
};