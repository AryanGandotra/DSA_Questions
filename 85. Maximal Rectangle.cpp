class Solution {
public:
    void getSmallestElementToLeft(vector<int>& setl, vector<int>& heights) {
        stack<pair<int, int>> st;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= heights[i])
                st.pop();

            if (st.empty())
                setl.push_back(-1);
            else
                setl.push_back(st.top().second);

            st.push({heights[i], i});
        }
    }

    void getSmallestElementToRight(vector<int>& setr, vector<int>& heights) {
        stack<pair<int, int>> st;
        int n = heights.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i])
                st.pop();

            if (st.empty())
                setr[i] = n;
            else
                setr[i] = st.top().second;

            st.push({heights[i], i});
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> setl;
        getSmallestElementToLeft(setl, heights);

        int n = heights.size();
        vector<int> setr(n);
        getSmallestElementToRight(setr, heights);

        int ans = INT_MIN;

        for (int i = 0; i < setl.size(); i++) {
            int width = setr[i] - setl[i] - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols = matrix[0].size();
        vector<int> vals(cols, 0);
        int ans = 0;

        for (int col = 0; col < cols; col++) {
            vals[col] = matrix[0][col]- '0';
        }

        ans = max(ans, largestRectangleArea(vals));

        for (int i = 1; i < matrix.size(); i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0')
                    vals[j] = 0;
                else {
                    vals[j] += 1;
                }
            }

            ans = max(ans, largestRectangleArea(vals));
        }

        return ans;
    }
};