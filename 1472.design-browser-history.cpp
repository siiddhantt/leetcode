/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory
{
public:
    int curr = 0;
    vector<string> hist;
    BrowserHistory(string homepage)
    {
        hist.push_back(homepage);
    }

    void visit(string url)
    {
        if (curr < hist.size() - 1)
            while (hist.size() - 1 != curr)
                hist.pop_back();
        hist.push_back(url);
        curr++;
    }

    string back(int steps)
    {
        if (curr - steps >= 0)
        {
            curr -= steps;
            return hist[curr];
        }
        curr = 0;
        return hist.front();
    }

    string forward(int steps)
    {
        if (curr + steps < hist.size())
        {
            curr += steps;
            return hist[curr];
        }
        curr = hist.size() - 1;
        return hist.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
