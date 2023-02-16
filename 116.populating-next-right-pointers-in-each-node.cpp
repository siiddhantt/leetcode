/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *rec(int i, vector<Node *> &vec)
    {
        if (i >= vec.size())
            return NULL;
        vec[i]->next = rec(i + 1, vec);
        return vec[i];
    }
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        map<int, vector<Node *>> m;
        queue<pair<int, Node *>> q;
        q.push({0, root});
        while (!q.empty())
        {
            auto p = q.front();
            int lvl = p.first;
            auto node = p.second;
            q.pop();
            if (node->left)
                q.push({lvl + 1, node->left});
            if (node->right)
                q.push({lvl + 1, node->right});
            m[lvl].push_back(node);
        }
        for (auto it : m)
            rec(0, it.second);
        return root;
    }
};
// @lc code=end
