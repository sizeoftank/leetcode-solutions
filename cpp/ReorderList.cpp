/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        int length = 0;
        stack<ListNode*> stk;
        if (head && head->next){
            ListNode *p1 = head;
            ListNode *p2 = head;
            while (p2 && p2->next){
                p1 = p1->next;
                p2 = p2->next->next;
            }
            while (p1->next){
                ListNode *n = p1->next;
                p1->next = n->next;
                stk.push(n);
            }
            p1 = head;
            while (!stk.empty()){
                ListNode *n = stk.top();
                stk.pop();
                n->next = p1->next;
                p1->next = n;
                p1 = n->next;
            }
        }
    }
};