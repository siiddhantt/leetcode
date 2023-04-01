/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k, vector<vector<bool>> &visited)
    {
        if (k == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[k])
            return false;
        visited[i][j] = true;
        for (auto &dir : dirs)
        {
            int ni = i + dir[0], nj = j + dir[1];
            if (dfs(board, word, ni, nj, k + 1, visited))
                return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (dfs(board, word, i, j, 0, visited))
                    return true;
        }
        return false;
    }
};

// @lc code=end
