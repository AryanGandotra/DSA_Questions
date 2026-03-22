class Solution
{
public:
    void func(int rowStart, int rowEnd, int colStart, int colEnd,
              vector<int> &ans, vector<vector<int>> &matrix)
    {
        if (rowStart > rowEnd || colStart > colEnd)
            return;

        // right
        for (int i = colStart; i <= colEnd; i++)
        {
            ans.push_back(matrix[rowStart][i]);
        }
        rowStart++;
        // down
        if (colStart <= colEnd && rowStart <= rowEnd)
        {
            for (int i = rowStart; i <= rowEnd; i++)
            {
                ans.push_back(matrix[i][colEnd]);
            }
        }
        colEnd--;
        // left
        if (colStart <= colEnd && rowStart <= rowEnd)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                ans.push_back(matrix[rowEnd][i]);
            }
        }
        rowEnd--;
        // up
        if (rowStart <= rowEnd && colStart <= colEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                ans.push_back(matrix[i][colStart]);
            }
        }
        colStart++;

        func(rowStart, rowEnd, colStart, colEnd, ans, matrix);
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> ans;
        func(0, rows - 1, 0, cols - 1, ans, matrix);
        return ans;
    }
};