/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_map<char, int>> col(board.size());
        for (int i = 0; i < board.size(); i++)
        {
            unordered_map<char, int> m;
            for (auto it : board[i])
            {
                if (it == '.')
                    continue;
                if (m.find(it) != m.end())
                    return false;
                m[it]++;
            }
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (col[j].find(board[i][j]) != col[j].end())
                    return false;
                col[j][board[i][j]]++;
            }
        }
        vector<int> delr = {-1, 0, 1, 0, -1, 1, -1, 1}, delc = {0, -1, 0, 1, -1, 1, 1, -1}, coor = {1, 4, 7};
        for (int i = 0; i < coor.size(); i++)
        {
            for (int j = 0; j < coor.size(); j++)
            {
                unordered_map<char, int> m;
                if (board[coor[i]][coor[j]] != '.')
                {
                    if (m.find(board[coor[i]][coor[j]]) != m.end())
                        return false;
                    m[board[coor[i]][coor[j]]]++;
                }
                for (int k = 0; k < 8; k++)
                {
                    int newr = coor[i] + delr[k], newc = coor[j] + delc[k];
                    if (board[newr][newc] == '.')
                        continue;
                    if (m.find(board[newr][newc]) != m.end())
                        return false;
                    m[board[newr][newc]]++;
                }
            }
        }
        return true;
    }
};
// @lc code=end
