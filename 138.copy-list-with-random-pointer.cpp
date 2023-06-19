/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        int i = 0;
        Node* iter = head;
        vector<Node*> vec;
        map<Node*, int> m;
        while(iter) {
            Node* node = new Node(iter->val);
            vec.push_back(node);
            m[iter] = i++;
            iter = iter->next;
        }
        Node* tmp = new Node(0);
        Node* ans = tmp;
        iter = head;
        for(int j = 0; j < i; j++) {
            if(j < i - 1)
                vec[j]->next = vec[j+1];
            if(iter->random)
                vec[j]->random = vec[m[iter->random]];
            else
                vec[j]->random = NULL;
            tmp->next = vec[j];
            tmp = tmp->next;
            iter = iter->next;
        }
        return ans->next;
    }
};
// @lc code=end

