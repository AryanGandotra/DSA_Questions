class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> vec(n + m, 0);

        int i = 0, j = 0, k = 0;

        while (i < n && j < m)
        {
            if (nums1[i] <= nums2[j])
            {
                vec[k++] = nums1[i++];
            }
            else
            {
                vec[k++] = nums2[j++];
            }
        }

        while (i < n)
        {
            vec[k++] = nums1[i++];
        }

        while (j < m)
        {
            vec[k++] = nums2[j++];
        }

        int size = vec.size();
        if (size % 2 == 0)
        {
            return (vec[size / 2] + vec[(size - 1) / 2]) * 1.0 / 2;
        }

        return vec[size / 2];
    }
};