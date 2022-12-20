/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &rooms, vector<int> &vis)
    {
        if (vis[i] != 0)
            return;
        vis[i] = 1;
        for (auto it : rooms[i])
            if (vis[it] == 0)
                dfs(it, rooms, vis);
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<int> vis(rooms.size(), 0);
        dfs(0, rooms, vis);
        for (auto it : vis)
            if (it == 0)
                return false;
        return true;
    }
};
// @lc code=end
