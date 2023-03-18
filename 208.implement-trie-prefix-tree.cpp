/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie
{
public:
    string s;
    unordered_map<string, int> m, pre;
    Trie()
    {
        s = "";
    }

    void insert(string word)
    {
        m[word]++;
        for (auto it : word)
        {
            s += it;
            pre[s]++;
        }
        s = "";
    }

    bool search(string word)
    {
        if (m.find(word) != m.end())
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        if (pre.find(prefix) != pre.end())
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
