class Solution
{
public:
    int getMaxElementRow(vector<vector<int>> &matrix, int rows, int cols,
                         int currCol)
    {
        int maxElement = -1;
        int index = -1;
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][currCol] >= maxElement)
            {
                maxElement = matrix[i][currCol];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int maxElementRow = getMaxElementRow(matrix, m, n, mid);

            int left = (mid - 1 >= 0) ? matrix[maxElementRow][mid - 1] : -1;
            int right = (mid + 1 < n) ? matrix[maxElementRow][mid + 1] : -1;

            if (matrix[maxElementRow][mid] > left &&
                matrix[maxElementRow][mid] > right)
                return {maxElementRow, mid};
            else if (matrix[maxElementRow][mid] < right)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {-1, -1};
    }
};