/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x)
    {
        s1.push(x);
        stack<int> t1 = s1, t2;
        t2.swap(s2);
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1 = t1;
    }

    int pop()
    {
        stack<int> t2;
        t2.swap(s1);
        int val = s2.top();
        s2.pop();
        stack<int> t1 = s2;
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2 = t1;
        return val;
    }

    int peek()
    {
        return s2.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
