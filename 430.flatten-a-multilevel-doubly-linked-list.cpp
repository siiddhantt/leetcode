/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *rec(Node *node)
    {
        if (node == NULL || (node->child == NULL && node->next == NULL))
            return node;
        Node *res;
        Node *tmp = node->next;
        if (node->child != NULL)
        {

            node->next = node->child;
            node->next->prev = node;
            node->child = NULL;
            res = rec(node->next);
            if (res != NULL && tmp != NULL)
            {
                res->next = tmp;
                tmp->prev = res;
            }
        }
        if (tmp != NULL)
            return rec(tmp);
        return rec(res);
    }
    Node *flatten(Node *head)
    {
        Node *tmp = head;
        rec(head);
        return tmp;
    }
};
// @lc code=end
