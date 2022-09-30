/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<pair<Node *, int>> q;
        map<int, vector<int>> m;
        q.push({root, 0});
        while (!q.empty())
        {
            auto tmp = q.front();
            Node *node = tmp.first;
            q.pop();
            int i = tmp.second;
            for (auto it : node->children)
            {
                q.push({it, i + 1});
            }
            m[i].push_back(node->val);
        }
        for (auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
// @lc code=end
