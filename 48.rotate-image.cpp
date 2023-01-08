/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int sr = 0, er = n - 1, sc = 0, ec = n - 1;
        while (sr < er && sc < ec)
        {
            queue<int> q;
            for (int i = sc; i <= ec; i++)
                q.push(matrix[sr][i]);
            for (int i = sr + 1; i < er; i++)
                q.push(matrix[i][ec]);
            for (int i = ec; i >= sc; i--)
                q.push(matrix[er][i]);
            for (int i = er - 1; i > sr; i--)
                q.push(matrix[i][sc]);
            // In-place rotation
            for (int i = sr; i <= er; i++)
            {
                matrix[i][ec] = q.front();
                q.pop();
            }
            for (int i = ec - 1; i > sc; i--)
            {
                matrix[er][i] = q.front();
                q.pop();
            }
            for (int i = er; i >= sr; i--)
            {
                matrix[i][sc] = q.front();
                q.pop();
            }
            for (int i = sc + 1; i < ec; i++)
            {
                matrix[sr][i] = q.front();
                q.pop();
            }
            sr++, sc++, er--, ec--;
        }
    }
};
// @lc code=end
