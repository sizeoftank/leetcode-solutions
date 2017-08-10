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
    bool hasCycle(ListNode *head) {
        ListNode* p1;
        ListNode* p2;
        if (head == NULL || head->next == NULL)
            return false;
        p1 = head;
        p2 = head->next;
        while (p2!=p1 && p2->next!=p1){
            p1 = p1->next;
            p2 = p2->next;
            if (p2==NULL || p2->next==NULL)
                return false;
            p2 = p2->next;
        }
        return true;
    }
};